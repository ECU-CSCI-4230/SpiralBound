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
#include <QItemSelectionModel>
#include <QTableWidget>
#include <QListWidgetItem>
#include <qinputdialog.h>
#include "book.h"
#include "section.h"
#include "page.h"
#include "util.h"
#include "addbook.h"

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

void MainWindow::on_action_open_triggered() {}
void MainWindow::on_action_test_triggered() {}
void MainWindow::on_action_save_triggered() {}

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

// Author:       Ketu Patel
// Init Date:    23.03.2019
// Last Updated: 23.03.2019
void MainWindow::receiveBookData(QString bookNm, QString authNm)
{
    qDebug() <<"mainWinow: Received data from addbook window" << bookNm <<authNm  ;
}

// Author:       Ketu Patel
// Init Date:    23.03.2019
// Last Updated: 23.03.2019
void MainWindow::on_action_new_triggered() {

    newBook = new addbook();
    newBook->setModal(true);
    newBook->show();

    connect(newBook, SIGNAL(sendBookData(QString, QString)), this, SLOT(receiveBookData(QString, QString)));
}

void MainWindow::on_action_openRecent_triggered() {}
void MainWindow::on_action_saveAs_triggered() {}
void MainWindow::on_action_bold_triggered() { me->bold(); }
void MainWindow::on_action_italic_triggered() { me->italic(); }
void MainWindow::on_action_strikethrough_triggered() { me->strikethough(); }
void MainWindow::on_action_underline_triggered() {}
void MainWindow::on_action_indent_triggered() {}
void MainWindow::on_action_unindent_triggered() {}
void MainWindow::on_action_bulletedList_triggered() {}
void MainWindow::on_action_numberedList_triggered() {}
void MainWindow::on_action_comment_triggered() {}

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
// Last Updated: 27.02.2019
void MainWindow::receiveAddData(QString eventName, QString eventDateTime)
{
    qDebug() << "mainwindow: Received data from addwindow" << eventName << eventDateTime;

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
// Last Updated: 19.02.2019
void MainWindow::on_pushButton_addEvent_clicked()
{
    QDate curDate = ui->calendarWidget->selectedDate();
    qDebug() << "mainwindow: Sending item from tableWidget_eventList to addcalendarevent";

   // Builds addcalendarevent GUI/window
   addWindow = new addcalendarevent(curDate ,this);
   addWindow->setModal(true);
   addWindow->show();

   // Connect mainwindow to addeventwindow
   connect(addWindow, SIGNAL(sendAddData(QString, QString)), this, SLOT(receiveAddData(QString, QString)));
}

// Author:       Nicholas
// Init Date:    19.02.2019
// Last Updated: 28.02.2019
void MainWindow::receiveEditData(QString eventName, QString eventDateTime)
{
    qDebug() << "mainwindow: Received data from addwindow" << eventName << eventDateTime;

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

        qDebug() << "mainwindow: Sending item from tableWidget_eventList to editcalendarevent";

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
       qDebug() << "mainwindow: Deleting item from tableWidget_eventList";

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
// Last Updated: 19.02.2019
void MainWindow::on_tableWidget_eventList_cellChanged(int row, int column)
{
    qDebug() << "mainwindow: Cell changed at:" << row << column;

    if(column == 2)
    {
        //sort
        qDebug() << "mainwindow: Time to sort";
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
// Last Updated: 20.03.2019
void MainWindow::on_pushButton_removePage_clicked()
{
    int* ind = Util::getSectionPage(ui->treeWidget_sections, ui->treeWidget_sections->selectedItems().front());

    if (ind[1] == -1) {
        // Deleting a section
        if (book->numSections() > 1) {
            QMessageBox::StandardButton reply = QMessageBox::question(this,
                "Delete Section", "Are you sure you want to delete this section?");

            if (reply == QMessageBox::Yes) {
                book->removeSection(ind[0]);
                ui->treeWidget_sections->takeTopLevelItem(ind[0]);

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
            sec->removePage(ind[1]);
            ui->treeWidget_sections->topLevelItem(ind[0])->takeChild(ind[1]);

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
// Last Updated: 26.02.2019
void MainWindow::receiveCardData(QString deckName, QString front, QString back)
{
    qDebug() << deckName << front << back;

    // Create row
    ui->tableWidget_cardsTable->insertRow(ui->tableWidget_cardsTable->rowCount() );
    // Populate row
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 0, new QTableWidgetItem(deckName));
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 1, new QTableWidgetItem(front));
    ui->tableWidget_cardsTable->setItem(ui->tableWidget_cardsTable->rowCount()-1, 2, new QTableWidgetItem(back));
}

// Author: Jamie, Nicholas
// Init Date:    09.02.2019
// Last Updated: 19.02.2019
void MainWindow::receiveCardDeleteData(bool response)
{
   if(response == true)
   {
       qDebug() << "mainwindow: Deleting item from tableWidget_eventList";

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

