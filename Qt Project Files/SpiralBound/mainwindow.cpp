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

//================
// Author:
// Init Date:
// Last Updated:
//================

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_eventList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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

// Author: Nicholas Ellis
// Init Date: 29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_about_triggered()
{
    AboutSpiralBound dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author: Tyler Rogers
// Init Date: 29.01.2019
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

// Author: Tyler Rogers (cirkuitbreaker)
// Init date: 29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_quit_triggered()
{
    QApplication::quit();
}

//-----------------------------------------------------------+
//                   Calendar Tab                            |
//-----------------------------------------------------------+
// Author: Nicholas
// Init Date: 19.02.2019
// Last Updated: 19.02.2019
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
    ui->tableWidget_eventList->setItem(row, 0, new QTableWidgetItem(date));
    ui->tableWidget_eventList->setItem(row, 1, new QTableWidgetItem(eventName));
    ui->tableWidget_eventList->setItem(row, 2, new QTableWidgetItem(time));
}

// Author: Nicholas, Cam, Jamie
// Init Date: 05.02.2019
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

// Author: Nicholas
// Init Date: 19.02.2019
// Last Updated: 19.02.2019
void MainWindow::receiveEditData(QString eventName, QString eventDateTime)
{
    qDebug() << "mainwindow: Received data from addwindow" << eventName << eventDateTime;

    // Seperate date from time
    QStringList datetime = eventDateTime.split(" ");
    QString date = datetime[0];
    QString time = datetime[1].append(" ").append(datetime[2]);

    // Populate current row
    int row = ui->tableWidget_eventList->currentRow();
    ui->tableWidget_eventList->setItem(row, 0, new QTableWidgetItem(date));
    ui->tableWidget_eventList->setItem(row, 1, new QTableWidgetItem(eventName));
    ui->tableWidget_eventList->setItem(row, 2, new QTableWidgetItem(time));
}

// Author: Nicholas
// Init Date: 09.02.2019
// Last Updated: 19.02.20119
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

// Author: Nicholas
// Init Date: 09.02.2019
// Last Updated: 19.02.20119
void MainWindow::receiveDeleteData(bool response)
{
   if(response == true)
   {
       qDebug() << "mainwindow: Deleting item from tableWidget_eventList";

       // Delete item from table
       ui->tableWidget_eventList->removeRow(ui->tableWidget_eventList->currentItem()->row());
   }
}

// Author: Jamie, Nicholas
// Init Date: 07.02.2019
// Last Updated: 19.02.20119
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

// Author: Nicholas
// Init Date: 19.02.2019
// Last Updated: 19.02.20119
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
