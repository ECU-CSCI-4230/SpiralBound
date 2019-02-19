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

    // TODO: add eventName and eventDateTime to the top of the table
    qDebug() << date << time;
}

// Author: Nicholas, Cam, Jamie
// Init Date: 05.02.2019
// Last Updated: 19.02.2019
void MainWindow::on_pushButton_addEvent_clicked()
{
    qDebug() << "mainwindow: Sending item from tableWidget_eventList to addcalendarevent";

   // Builds addcalendarevent GUI/window
   addWindow = new addcalendarevent(this);
   addWindow->setModal(true);
   addWindow->show();

    // Connect mainwindow to addeventwindow
   connect(addWindow, SIGNAL(sendAddData(QString, QString)), this, SLOT(receiveAddData(QString, QString)));

}

// Author: Nicholas
// Init Date: 09.02.2019
// Last Updated: 14.02.20119
void MainWindow::on_pushButton_editEvent_clicked()
{
    // If user did not select an event from the event list
    if(ui->tableWidget_eventList->currentItem() == nullptr)
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Select event to edit, please try again.");
        messageBox.setFixedSize(500,200);
    }
    else
    {
         qDebug() << "mainwindow: Sending item from tableWidget_eventList to editcalendarevent";

        // Builds editcalendarevent GUI/window
        editWindow = new editcalendarevent(this);
        editWindow->setModal(true);
        editWindow->show();

        // Connect mainwindow to editcalendarevent window
        //connect(this, SIGNAL(sendEditData(QTableWidgetItem *)), editWindow, SLOT(receiveEditData(QTableWidgetItem *)));

        // Send selected item to editcalendarevent window
        //QTableWidgetItem *item = ui->tableWidget_eventList->currentItem();
        //emit sendData(item);
    }
}

// Author: Jamie, Nicholas
// Init Date: 07.02.2019
// Last Updated: 07.02.20119
void MainWindow::on_pushButton_deleteEvent_clicked()
{
    // Builds deletecalendarevent GUI/window
    deletecalendarevent dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author: Nicholas
// Init Date: 09.02.2019
// Last Updated: 09.02.20119
void MainWindow::on_pushButton_printEventList_clicked()
{
    qDebug("mainwindow: tableWidget_eventList:");

    // Print all items in event list
}
