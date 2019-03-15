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
#include "block.h"

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
    book->addSection("New Section 1", "");
    book->getSection(0)->addPage("Untitled Page");
    ui->textEdit->setDocument(book->getSection(0)->getPage(0)->getContent());
    ui->listWidget_pages->setCurrentRow(0);
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

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_open_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_test_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_save_triggered()
{

}

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
void MainWindow::on_action_aboutQt_triggered()
{
    QApplication::aboutQt();
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_crashCourse_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_print_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_new_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_openRecent_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_saveAs_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_bold_triggered()
{
    me->bold();
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_italic_triggered()
{
    me->italic();
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_underline_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_comment_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_strikethrough_triggered()
{
    me->strikethough();
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_indent_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_unindent_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_bulletedList_triggered()
{
}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_numberedList_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_taskList_triggered()
{

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_preferences_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_printPreview_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_export_triggered()
{

}

// Author:       Tyler Rogers (cirkuitbreaker)
// Init date:    29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_quit_triggered()
{
    QApplication::quit();
}

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
// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 12.03.2019
void MainWindow::on_pushButton_AddPage_clicked()
{
    // Add Untitled Page and switch to it
    ui->listWidget_pages->addItem(new QListWidgetItem("Untitled Page"));
    book->getSection(ui->tabWidget_2->currentIndex())->addPage("Untitled Page");
    ui->listWidget_pages->setCurrentRow(ui->listWidget_pages->count()-1);
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_tabWidget_2_tabCloseRequested(int index)
{
    if (ui->tabWidget_2->count() > 1) {
        // Only remove a section if there is another available
        book->removeSection(index);
        ui->tabWidget_2->removeTab(index);
    }
    else {
    }
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 13.03.2019
void MainWindow::on_pushButton_addSection_clicked()
{
    // Adds a section
    ui->tabWidget_2->addTab(new QWidget(), QString("New Section %0").arg(ui->tabWidget_2->count()+1));
    ui->tabWidget_2->setCurrentIndex(ui->tabWidget_2->count()-1);
    book->addSection(ui->tabWidget_2->tabText(ui->tabWidget_2->count()-1), "");
    book->getSection(book->numSections()-1)->addPage("Untitled Page");

    // Update the list of pages
    Section* sec = book->getSection(ui->tabWidget_2->currentIndex());
    ui->listWidget_pages->clear();
    for(int i=0; i<sec->numPages(); i++) {
        ui->listWidget_pages->addItem(new QListWidgetItem(sec->getPage(i)->getPageName()));
    }
    ui->listWidget_pages->setCurrentRow(0);
    ui->textEdit->setDocument(sec->getPage(0)->getContent());
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_tabWidget_2_tabBarDoubleClicked(int index)
{
    // Rename a section, but ONLY if the new name isn't blank
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Rename Section", "New Name:", QLineEdit::Normal, book->getSection(index)->getSecName(), &ok);

    if (ok && !text.isEmpty()) {
        book->getSection(index)->setName(text);
        ui->tabWidget_2->setTabText(index, text);
    }
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 13.03.2019
void MainWindow::on_tabWidget_2_currentChanged(int index) {
    // Change the listing of pages to be based on the current section
    Section* sec = book->getSection(index);

    if (sec != nullptr) {
        // Update the list of pages
        ui->listWidget_pages->clear();
        for(int i=0; i<sec->numPages(); i++) {
            ui->listWidget_pages->addItem(new QListWidgetItem(sec->getPage(i)->getPageName()));
        }
        ui->listWidget_pages->setCurrentRow(0);
        ui->textEdit->setDocument(book->getSection(ui->tabWidget_2->currentIndex())->getPage(0)->getContent());
    }
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 13.03.2019
void MainWindow::on_listWidget_pages_currentRowChanged(int currentRow) {
    Page* cur = book->getSection(ui->tabWidget_2->currentIndex())->getPage(currentRow);
    if (cur != nullptr) {
        ui->textEdit->setDocument(cur->getContent());
    }
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 11.03.2019
/** findItemIndex(item,wid) will find the numerical index of an item, item, in a list widget
  * wid, returning the index, or -1 if the item is not found in the widget. */
int findItemIndex(QListWidgetItem* item, QListWidget* wid) {
    for(int i=0; i<wid->count(); i++) {
        if (wid->item(i) == item) { return i; }
    }
    return -1;
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_listWidget_pages_itemDoubleClicked(QListWidgetItem* item) {
    // Allow renaming of a page if the new name isn't blank
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Rename Page", "New Name:", QLineEdit::Normal, item->text(), &ok);
    int index = findItemIndex(item, ui->listWidget_pages);

    if (ok && !text.isEmpty()) {
        Section* sec = book->getSection(ui->tabWidget_2->currentIndex());
        sec->getPage(index)->setPgName(text);
        item->setText(text);
    }
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    13.03.2019
// Last Updated: 13.03.2019
void MainWindow::on_pushButton_removePage_clicked()
{
    // Delete page if it isn't the only one left
    if (ui->listWidget_pages->count() > 1) {
        QList<QListWidgetItem*> its = ui->listWidget_pages->selectedItems();
        foreach(QListWidgetItem *it, its) {
            int row = ui->listWidget_pages->row(it);
            ui->listWidget_pages->takeItem(row);
            book->getSection(ui->tabWidget_2->currentIndex())->removePage(row);
        }
    }

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
