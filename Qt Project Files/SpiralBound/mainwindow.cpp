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
    book->addSection("New Section 1", "");
    book->getSection(0)->addPage("Untitled Page");
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

}

// Author:
// Init Date:
// Last Updated:
void MainWindow::on_action_italic_triggered()
{

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
// Last Updated: 11.03.2019
void MainWindow::on_pushButton_AddPage_clicked()
{
    // Add Untitled Page
    QListWidgetItem* pItem = new QListWidgetItem("Untitled Page");
    // pItem->setForeground(Qt::black);
    // pItem->setBackground(Qt::gray);
    ui->listWidget_pages->addItem(pItem);

    book->getSection(ui->tabWidget_2->currentIndex())->addPage("Untitled Page");
    qDebug() << "New page added to section \"" << book->getSection(ui->tabWidget_2->currentIndex())->getSecName() << "\"";
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_tabWidget_2_tabCloseRequested(int index)
{
    qDebug() << book->getSection(index)->getSecName() << " was removed";
    book->removeSection(index);
    ui->tabWidget_2->removeTab(index);
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_pushButton_addSection_clicked()
{
    // Adds a section
    ui->tabWidget_2->addTab(new QWidget(), QString("New Section %0").arg(ui->tabWidget_2->count()+1));
    ui->tabWidget_2->setCurrentIndex(ui->tabWidget_2->count()-1);
    book->addSection(ui->tabWidget_2->tabText(ui->tabWidget_2->count()-1), "");
    qDebug() << book->getSection(book->numSections()-1)->getSecName() << " was added";

    QPalette pal = palette();

    // set gray background
    if (ui->tabWidget_2->count() % 2 == 0 )
    {
        pal.setColor(QPalette::Background, Qt::gray);
        ui->tabWidget_2->setPalette(pal);
        ui->tabWidget_2->setAutoFillBackground(true);
    }
    on_tabWidget_2_currentChanged(ui->tabWidget_2->currentIndex());
}

// Author:       Ketu Patel, Matthew Morgan
// Init Date:    10.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_tabWidget_2_tabBarDoubleClicked(int index)
{
    // Rename a section, but ONLY if the new name isn't blank
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Rename Section", "New Name:", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
      qDebug() << "Section \"" << book->getSection(index)->getSecName() << "\" renamed to " << text;
      book->getSection(index)->setName(text);
      ui->tabWidget_2->setTabText(index, text);
    }
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_tabWidget_2_currentChanged(int index) {
    // Change the listing of pages to be based on the current section
    Section* sec = book->getSection(index);

    if (sec != nullptr) {
        qDebug() << "Section changed to " << sec->getSecName();
        ui->listWidget_pages->clear();
        for(int i=0; i<sec->numPages(); i++) {
            ui->listWidget_pages->addItem(new QListWidgetItem(sec->getPage(i)->getPageName()));
        }
        ui->listWidget_pages->setCurrentRow(0);
    }
}

// Author:       Matthew Morgan
// Init Date:    11.03.2019
// Last Updated: 11.03.2019
void MainWindow::on_listWidget_pages_currentRowChanged(int currentRow) {
    Page* cur = book->getSection(ui->tabWidget_2->currentIndex())->getPage(currentRow);
    if (cur != nullptr) {
        qDebug() << "Page changed to " << cur->getPageName();
    }
}
