#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutspiralbound.h"
#include "addcalendarevent.h"
#include "deletecalendarevent.h"
#include "editcalendarevent.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QtDebug>
#include <QItemSelectionModel>
#include <QTableWidget>
#include <QListWidgetItem>
#include <qinputdialog.h>
#include "book.h"
#include "section.h"
#include "page.h"
#include "util.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_eventList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    book = new Book("", "");
    me = new MarkdownEditor(ui->textEdit);

    // Add a default section, page, and change to view that page in that section on startup
    book->addSection("Section 01");
    book->getSection(0)->addPage("Untitled Page");
    ui->textEdit->setDocument(book->getSection(0)->getPage(0)->getContent());
    ui->treeWidget_sections->setItemSelected(ui->treeWidget_sections->topLevelItem(0)->child(0), true);
    ui->treeWidget_sections->topLevelItem(0)->setExpanded(true);

    ui->tableWidget_cardsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//-----------------------------------------------------------+
//                    Menu Bar Buttons                       |
//-----------------------------------------------------------+
// Author:       Nicholas Ellis
// Init Date:    29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_about_triggered()
{
    AboutSpiralBound dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author:       Tyler Rogers
// Init Date:    29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_aboutQt_triggered() { QApplication::aboutQt(); }

void MainWindow::on_action_crashCourse_triggered() {}
void MainWindow::on_action_print_triggered() {}
void MainWindow::on_action_new_triggered() {}
void MainWindow::on_action_openRecent_triggered() {}

// Author:       Matthew Morgan
// Init Date:    21.03.2019
// Last Updated: 21.03.2019
void MainWindow::on_action_open_triggered() {
    // Get the directory of the notebook and check for the about file's existence
    // QString dir = QFileDialog::getExistingDirectory(this, "Select Notebook Directory", QString(QDir::homePath()));
    QString dir = "F:/Academic/Source/SpiralBound/SampleNotebook";

    try {
        for(int i=ui->tableWidget_eventList->rowCount(); i>0; i--)
            ui->tableWidget_eventList->removeRow(0);

        for(int i=ui->tableWidget_cardsTable->rowCount(); i>0; i--)
            ui->tableWidget_cardsTable->removeRow(0);

        Book* nBook;
        QString about = QString("%1/about.txt").arg(dir);
        QFile* read = new QFile(about);

        if (!QFile::exists(about))
            throw "The selected directory is not detected as a notebook!";

        if (!read->open(QFile::ReadOnly))
            throw "The notebook's 'about' file couldn't be opened!";

        // -----------------------------------------------------------------------------
        // Open the book file and read in it's information
        QTextStream str(&*read);

        QString name = str.readLine(),
                auth = str.readLine(),
                date = str.readLine();
        QStringList datePiece = date.split("-");

        nBook = new Book(name, auth);
        nBook->setDate(QDate(datePiece.at(0).toInt(), datePiece.at(1).toInt(), datePiece.at(2).toInt()));

        // -----------------------------------------------------------------------------
        // Read in the study decks
        connect(this, SIGNAL(loadCard(QString, QString, QString)), this, SLOT(receiveCardData(QString, QString, QString)));

        for(int i=str.readLine().toInt(); i>0; i--) {
            // Read in a single study deck
            QString deckName = str.readLine();
            QFile* deck = new QFile(QString("%1/study/%2.csv").arg(dir).arg(i));

            if (!deck->open(QFile::ReadOnly))
                throw "A study deck couldn't be read; there may be corruption!";

            QTextStream deckStr(&*deck);

            while(!deckStr.atEnd()) {
                // Card format is <n>,<front>,<back>, where <n> specifies where to split the front/back from
                // As such, parse <n>, then remove '<n>,' from the string, then parse the front/back
                QString card = deckStr.readLine();
                int ind = card.left(card.indexOf(',')).toInt();
                card = card.right(card.length()-card.indexOf(',')-1);
                emit loadCard(deckName, card.left(ind), card.right(card.length()-ind-1));
            }

            deck->close();
            delete deck;
        }

        disconnect(this, SIGNAL(loadCard(QString, QString, QString)), this, SLOT(receiveCardData(QString, QString, QString)));

        read->close();
        delete read;

        // -----------------------------------------------------------------------------
        // Read in calendar events, but only if the cal.csv file exists
        read = new QFile(QString("%1/cal.csv").arg(dir));

        if (read->exists()) {
            if (!read->open(QFile::ReadOnly))
                throw "The notebook's calendar events couldn't be loaded!";

            QTextStream cal(&*read);

            connect(this, SIGNAL(loadEvent(QString, QString)), this, SLOT(receiveAddData(QString, QString)));

            while(!cal.atEnd()) {
                QStringList event = cal.readLine().split(",");
                emit loadEvent(event.at(1), QString("%1 %2").arg(event.at(0)).arg(event.at(2)));
            }

            disconnect(this, SIGNAL(loadEvent(QString, QString)), this, SLOT(receiveAddData(QString, QString)));
        }

        read->close();
        delete read;

        // -----------------------------------------------------------------------------
        // Read in notebook sections
        QDir sec = QDir(QString("%1/sections").arg(dir));
        sec.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

        // For every section, we will:
        // + Open the 'about.txt' file for that section to get the name, color, and summary
        // + Iterate through every page of the section and add them to the section
        for(QString section : sec.entryList()) {
            QFile* about = new QFile(QString("%1/%2/about.txt").arg(sec.path()).arg(section));
            QDir pgs = QDir(QString("%1/%2").arg(sec.path()).arg(section)); // Should point to <path>/sections/<sec>
            pgs.setFilter(QDir::Files);

            if (!about->open(QFile::ReadOnly))
                throw "The about file for a section couldn't be opened!";

            QTextStream abStr(*&about);
            QString secName = abStr.readLine(),
                    secCol = abStr.readLine(),
                    secCont = abStr.readAll();

            int ind = nBook->numSections();
            nBook->addSection(secName);
            nBook->getSection(ind)->setDoc(new QTextDocument(secCont));
            nBook->getSection(ind)->setColor(QColor(secCol));

            about->close();
            delete about;

            // Read in pages
            for(QString pg : pgs.entryList()) {
                QFile* page = new QFile(QString("%1/%2").arg(pgs.path()).arg(pg));

                // Skip the 'about' file since it was already used
                if (page->fileName().split('/').last() == "about.txt") {
                    delete page;
                    continue;
                }

                if (!page->open(QFile::ReadOnly))
                    throw "A page couldn't be read for a section!";

                QTextStream pgStream(*&page);
                QString pgName = pgStream.readLine(),
                        pgDate = pgStream.readLine(),
                        pgCont = pgStream.readAll();
                QStringList datePiece = pgDate.split("-");

                int indPg = nBook->getSection(ind)->numPages();
                nBook->getSection(ind)->addPage(pgName);
                nBook->getSection(ind)->getPage(indPg)->setDate(QDate(datePiece.at(0).toInt(), datePiece.at(1).toInt(), datePiece.at(2).toInt()));
                nBook->getSection(ind)->getPage(indPg)->setContent(new QTextDocument(pgCont));

                delete page;
            }
        }

        // Update the notebook interface to reflect the new book
        ui->treeWidget_sections->clear();

        for(int i=nBook->numSections()-1; i>=0; i--) {
            QTreeWidgetItem* item = new QTreeWidgetItem();
            QBrush pal = item->background(0);

            // Set the item's properties after inserting it
            pal.setColor(nBook->getSection(i)->getColor());
            pal.setStyle(Qt::BrushStyle::SolidPattern);
            item->setBackground(0, pal);
            item->setText(0, nBook->getSection(i)->getSecName());
            ui->treeWidget_sections->insertTopLevelItem(0, item);

            for(int k=nBook->getSection(i)->numPages()-1; k>=0; k--) {
                QTreeWidgetItem* pg = new QTreeWidgetItem();
                pg->setText(0, nBook->getSection(i)->getPage(k)->getPageName());
                item->insertChild(0, pg);
            }
        }

        // Select the first section's summary
        ui->treeWidget_sections->topLevelItem(0)->setExpanded(true);
        ui->treeWidget_sections->topLevelItem(0)->child(0)->setSelected(true);
        ui->textEdit->setDocument(nBook->getSection(0)->getPage(0)->getContent());

        delete book;
        book = nBook;
    }
    catch(exception& e) {
        qDebug() << "Woopsie: " << e.what();
        Util::showError("Load Error", "The notebook you selected couldn't be loaded.");
    }
    catch(...) { qDebug() << "Woopsie..."; }
}

// Author:       Matthew Morgan
// Init Date:    21.03.2019
// Last Updated: 21.03.2019
void MainWindow::on_action_save_triggered() {

}

// Author:       Matthew Morgan
// Init Date:    21.03.2019
// Last Updated: 21.03.2019
void MainWindow::on_action_saveAs_triggered() {

}

void MainWindow::on_action_bold_triggered() { me->bold(); }
void MainWindow::on_action_italic_triggered() { me->italic(); }
void MainWindow::on_action_strikethrough_triggered() { me->strikethough(); }
void MainWindow::on_action_underline_triggered() {}
void MainWindow::on_action_indent_triggered() {}
void MainWindow::on_action_unindent_triggered() {}
void MainWindow::on_action_bulletedList_triggered() {}
void MainWindow::on_action_numberedList_triggered() {}
void MainWindow::on_action_comment_triggered() {}

void MainWindow::on_action_test_triggered() {}
void MainWindow::on_action_taskList_triggered() {}
void MainWindow::on_action_preferences_triggered() {}
void MainWindow::on_action_printPreview_triggered() {}
void MainWindow::on_action_export_triggered() {}

// Author:       Tyler Rogers (cirkuitbreaker)
// Init date:    29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_quit_triggered() { QApplication::quit(); }

//-----------------------------------------------------------+
//                   Calendar Tab                            |
//-----------------------------------------------------------+
// Author:       Nicholas, Matthew
// Init Date:    19.02.2019
// Last Updated: 22.03.2019
void MainWindow::receiveAddData(QString eventName, QString eventDateTime)
{
    // Seperate date from time
    QStringList datetime = eventDateTime.split(" ");
    QString date = datetime[0];
    QString time = datetime[1].append(" ").append(datetime[2]);

    // Create row
    ui->tableWidget_eventList->insertRow(ui->tableWidget_eventList->rowCount() );
    // Populate row
    int row = ui->tableWidget_eventList->rowCount()-1;
    ui->tableWidget_eventList->setSortingEnabled(false);
    ui->tableWidget_eventList->setItem(row, 0, new QTableWidgetItem(date));
    ui->tableWidget_eventList->setItem(row, 1, new QTableWidgetItem(eventName));
    ui->tableWidget_eventList->setItem(row, 2, new QTableWidgetItem(time));
    ui->tableWidget_eventList->setSortingEnabled(true);
}

// Author:       Nicholas, Cam, Jamie
// Init Date:    05.02.2019
// Last Updated: 22.03.2019
void MainWindow::on_pushButton_addEvent_clicked()
{
    QDate curDate = ui->calendarWidget->selectedDate();

   // Builds addcalendarevent GUI/window
   addWindow = new addcalendarevent(curDate ,this);
   addWindow->setModal(true);
   addWindow->show();

   // Connect mainwindow to addeventwindow
   connect(addWindow, SIGNAL(sendAddData(QString, QString)), this, SLOT(receiveAddData(QString, QString)));
}

// Author:       Nicholas
// Init Date:    19.02.2019
// Last Updated: 22.03.2019
void MainWindow::receiveEditData(QString eventName, QString eventDateTime)
{
    // Seperate date from time
    QStringList datetime = eventDateTime.split(" ");
    QString date = datetime[0];
    QString time = datetime[1].append(" ").append(datetime[2]);

    // Populate current row
    int row = ui->tableWidget_eventList->currentRow();
    ui->tableWidget_eventList->setSortingEnabled(false);
    ui->tableWidget_eventList->setItem(row, 0, new QTableWidgetItem(date));
    ui->tableWidget_eventList->setItem(row, 1, new QTableWidgetItem(eventName));
    ui->tableWidget_eventList->setItem(row, 2, new QTableWidgetItem(time));
    ui->tableWidget_eventList->setSortingEnabled(true);
}

// Author:       Nicholas
// Init Date:    09.02.2019
// Last Updated: 19.02.2019
void MainWindow::on_pushButton_editEvent_clicked()
{
    QTableWidgetItem *item = ui->tableWidget_eventList->currentItem();
    int row = ui->tableWidget_eventList->currentRow();
    ui->tableWidget_eventList->selectRow(row);

    // If user did not select an event from the event list
    if(item == nullptr)
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Select event to edit, please try again.");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        QString date = ui->tableWidget_eventList->item(row, 0)->text();
        QString name = ui->tableWidget_eventList->item(row, 1)->text();
        QString time = ui->tableWidget_eventList->item(row, 2)->text();

        // Builds editcalendarevent GUI/window
        editWindow = new editcalendarevent(this);
        editWindow->setModal(true);
        editWindow->show();

        // Connect mainwindow to editcalendarevent window
        connect(this, SIGNAL(sendEditData(QString, QString, QString)), editWindow, SLOT(receiveEditData(QString, QString, QString)));

        // Send selected item to editcalendarevent window
        emit sendEditData(date, name, time);

        // Connect editcalendarevent to maindwindow
        connect(editWindow, SIGNAL(sendEditData(QString, QString)), this, SLOT(receiveEditData(QString, QString)));
    }
}
// Author:       Nicholas
// Init Date:    09.02.2019
// Last Updated: 19.02.2019
void MainWindow::receiveDeleteData(bool response)
{
   if(response == true)
   {
       // Delete item from table
       ui->tableWidget_eventList->removeRow(ui->tableWidget_eventList->currentItem()->row());
   }
}

// Author:       Jamie, Nicholas
// Init Date:    07.02.2019
// Last Updated: 19.02.2019
void MainWindow::on_pushButton_deleteEvent_clicked()
{
    // Get current selected row
    QTableWidgetItem *item = ui->tableWidget_eventList->currentItem();

    if(item == nullptr)
        {
            QMessageBox messageBox;
            messageBox.critical(nullptr,"Error","Select event to edit, please try again.");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            // Builds deletecalendarevent GUI/window
            deleteWindow = new deletecalendarevent(this);
            deleteWindow->setModal(true);
            deleteWindow->show();

            // Connect mainwindow to addeventwindow
            connect(deleteWindow, SIGNAL(sendDeleteData(bool)), this, SLOT(receiveDeleteData(bool)));
        }
}

// Author:       Nicholas
// Init Date:    19.02.2019
// Last Updated: 22.03.2019
void MainWindow::on_tableWidget_eventList_cellChanged(__attribute__((unused)) int row, int column)
{
    if(column == 2)
    {
        ui->tableWidget_eventList->sortByColumn(0, Qt::AscendingOrder);
    }
}

//-----------------------------------------------------------+
//                   Notetake Tab                            |
//-----------------------------------------------------------+
// Author:       Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 20.03.2019
void MainWindow::on_pushButton_addPage_clicked()
{
    // Add a new page to the section, and activate it as the current
    int* ind = Util::getSectionPage(ui->treeWidget_sections, ui->treeWidget_sections->selectedItems().front());
    QTreeWidgetItem* pg = new QTreeWidgetItem();

    book->getSection(ind[0])->addPage("Untitled Page");
    ui->treeWidget_sections->topLevelItem(ind[0])->addChild(pg);
    ui->treeWidget_sections->clearSelection();
    pg->setText(0, "Untitled Page");
    pg->setSelected(true);
    on_treeWidget_sections_itemClicked(pg, 0);

    delete ind;
}

// Author:       Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 20.03.2019
void MainWindow::on_pushButton_addSection_clicked()
{
    // Add a new section and page, and update the tree to reflect these changes
    // Clear the page selection
    int size = book->numSections();
    QTreeWidgetItem *sec = new QTreeWidgetItem(), *pg = new QTreeWidgetItem();

    book->addSection(QString("New Section %1").arg(book->numSections()+1));
    book->getSection(size)->addPage("Untitled Page");

    ui->treeWidget_sections->addTopLevelItem(sec);
    sec->setText(0, book->getSection(size)->getSecName());
    sec->addChild(pg);
    pg->setText(0, "Untitled Page");

    ui->treeWidget_sections->setItemExpanded(sec, true);
    ui->treeWidget_sections->clearSelection();
    pg->setSelected(true);
    on_treeWidget_sections_itemClicked(pg, 0);
}

// Author:       Matthew Morgan
// Init Date:    20.03.2019
// Last Updated: 20.03.2019
void MainWindow::on_treeWidget_sections_itemDoubleClicked(QTreeWidgetItem *item, int column) {
    int* ind = Util::getSectionPage(ui->treeWidget_sections, item);

    if (ind[1] > -1) {
        // Allow renaming of a page if the new name isn't blank
        bool ok;
        QString text = QInputDialog::getText(nullptr, "Rename Page", "New Name:", QLineEdit::Normal, item->text(column), &ok);

        if (ok && !text.isEmpty()) {
            Section* sec = book->getSection(ind[0]);
            sec->getPage(ind[1])->setPgName(text);
            item->setText(column, text);
        }
    }
    else {
        // Changing section information
        // Instantiate the window, then send the data and wait to receive updated data
        editSectionWindow = new editsection(this);
        editSectionWindow->setModal(true);
        editSectionWindow->show();

        Section* sec = book->getSection(ind[0]);
        connect(this, SIGNAL(sendSectionInfo(QString, QColor, int)), editSectionWindow, SLOT(receiveSectionData(QString, QColor, int)));
        emit sendSectionInfo(sec->getSecName(), sec->getColor(), ind[0]);
        connect(editSectionWindow, SIGNAL(sendSectionData(QString, QColor, int)), this, SLOT(receiveSectionData(QString, QColor, int)));
    }

    delete ind;
}

// Author:       Matthew Morgan
// Init Date:    20.03.2019
// Last Updated: 20.03.2019
void MainWindow::on_treeWidget_sections_itemClicked(QTreeWidgetItem* item, __attribute__((unused)) int column) {
    // Dynamically update the content being displayed - section info or page content
    int* ind = Util::getSectionPage(ui->treeWidget_sections, item);

    if (ind[1] == -1) {
        ui->textEdit->setDocument(book->getSection(ind[0])->getDoc());
    }
    else {
        ui->textEdit->setDocument(book->getSection(ind[0])->getPage(ind[1])->getContent());
    }

    delete ind;
}

// Author:       Matthew Morgan
// Init Date:    20.03.2019
// Last Updated: 20.03.2019
void MainWindow::receiveSectionData(QString nm, QColor col, int ind) {
    // Update the section's color and name
    Section* sec = book->getSection(ind);
    sec->setName(nm);
    sec->setColor(col);

    ui->treeWidget_sections->topLevelItem(ind)->setText(0, nm);
    QBrush pal = ui->treeWidget_sections->palette().background();
    pal.setColor(col);
    pal.setStyle(Qt::BrushStyle::SolidPattern);
    ui->treeWidget_sections->topLevelItem(ind)->setBackground(0, pal);
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    13.03.2019
// Last Updated: 22.03.2019
void MainWindow::on_pushButton_removePage_clicked()
{
    int* ind = Util::getSectionPage(ui->treeWidget_sections, ui->treeWidget_sections->selectedItems().first());

    if (ind[1] == -1) {
        // Deleting a section
        if (book->numSections() > 1) {
            QMessageBox::StandardButton reply = QMessageBox::question(this,
                "Delete Section", "Are you sure you want to delete this section?");

            if (reply == QMessageBox::Yes) {
                delete ui->treeWidget_sections->topLevelItem(ind[0]);
                book->removeSection(ind[0]);

                // Move to the first page of the first section
                ui->treeWidget_sections->clearSelection();
                ui->treeWidget_sections->topLevelItem(0)->setExpanded(true);
                ui->treeWidget_sections->topLevelItem(0)->child(0)->setSelected(true);
                on_treeWidget_sections_itemClicked(ui->treeWidget_sections->topLevelItem(0)->child(0), 0);
            }
        }
        else {
            QMessageBox msg;
            msg.critical(nullptr, "Error", "Cannot delete the last section of the notebook!");
            msg.setFixedSize(500, 200);
        }
    }
    else {
        // Deleting a page
        Section* sec = book->getSection(ind[0]);

        if (sec->numPages() > 1) {
            ui->treeWidget_sections->topLevelItem(ind[0])->takeChild(ind[1]);
            sec->removePage(ind[1]);

            // Select the first page of the section from which the page was removed
            ui->treeWidget_sections->clearSelection();
            ui->treeWidget_sections->topLevelItem(ind[0])->setExpanded(true);
            ui->treeWidget_sections->topLevelItem(ind[0])->child(0)->setSelected(true);
            on_treeWidget_sections_itemClicked(ui->treeWidget_sections->topLevelItem(ind[0])->child(0), 0);
        }
        else {
            QMessageBox msg;
            msg.critical(nullptr, "Error", "Cannot delete the only page of a section!");
            msg.setFixedSize(500, 200);
        }
    }

    delete ind;
}

// Author:       Matthew Morgan
// Init Date:    21.03.2019
// Last Updated: 21.03.2019
void MainWindow::on_treeWidget_sections_currentItemChanged(QTreeWidgetItem *cur, __attribute__((unused)) QTreeWidgetItem *prev) {
    if (cur == nullptr) { return; }
    on_treeWidget_sections_itemClicked(cur, 0);
}

void MainWindow::on_pushButton_bold_clicked() {}
void MainWindow::on_pushButton_italics_clicked() {}
void MainWindow::on_pushButton_underline_clicked() {}
void MainWindow::on_pushButton_bulleted_clicked() {}
void MainWindow::on_pushButton_numbered_clicked() {}
void MainWindow::on_pushButton_save_clicked() {}
void MainWindow::on_pushButton_strike_clicked() {}
void MainWindow::on_pushButton_undent_clicked() {}
void MainWindow::on_pushButton_indent_clicked() {}

//-----------------------------------------------------------+
//                     Flash Card Tab                        |
//-----------------------------------------------------------+
// Author: Nick
// Init Date:    26.02.2019
// Last Updated: 22.03.2019
void MainWindow::receiveCardData(QString deckName, QString front, QString back)
{
    // Create row
    ui->tableWidget_cardsTable->insertRow(ui->tableWidget_cardsTable->rowCount() );
    // Populate row
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 0, new QTableWidgetItem(deckName));
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 1, new QTableWidgetItem(front));
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 2, new QTableWidgetItem(back));
}

// Author: Jamie, Nicholas
// Init Date:    09.02.2019
// Last Updated: 22.03.2019
void MainWindow::receiveCardDeleteData(bool response)
{
   if(response == true)
   {
       // Delete item from table
       ui->tableWidget_cardsTable->removeRow(ui->tableWidget_cardsTable->currentItem()->row());
   }
}

// Author: Jamie, Nick
// Init Date:    26.02.2019
// Last Updated: 26.02.2019
void MainWindow::on_pushButton_addCard_clicked()
{
    addCardWindow = new addcard(this);
    addCardWindow->setModal(true);
    addCardWindow->show();

    connect(addCardWindow, SIGNAL(sendCardData(QString,QString,QString)), this, SLOT(receiveCardData(QString, QString, QString)));
}

// Author: Jamie
// Init Date: 12.03.2019
// Last Updated: 12.03.2019
void MainWindow::on_pushButton_deleteCard_clicked()
{
    // TODO: open window for deleting selected deck.
    // Get current selected row
    QTableWidgetItem *item = ui->tableWidget_cardsTable->currentItem();

    if(item == nullptr)
        {
            QMessageBox messageBox;
            messageBox.critical(nullptr,"Error","Select a card to delete, please try again.");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            // Builds deletecard GUI/window
            deleteCardWindow = new deletecard(this);
            deleteCardWindow->setModal(true);
            deleteCardWindow->show();

            // Connect mainwindow to addeventwindow
            connect(deleteCardWindow, SIGNAL(sendDeleteData(bool)), this, SLOT(receiveCardDeleteData(bool)));
        }
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_pushButton_studyCard_clicked()
{
    // TODO: open study window for selected deck.
}

// Author: Cam
// Init Date: 02.03.2019
// Last Updated: 07.03.2019
void MainWindow::on_pushButton_import_clicked()
{
    //TODO: opens window for importing files
    importCardWindow = new importflashcards(this);
    importCardWindow->setModal(true);
    importCardWindow->show();

    connect(importCardWindow, SIGNAL(sendCardData(QString,QString,QString)), this, SLOT(receiveCardData(QString, QString, QString)));
}
