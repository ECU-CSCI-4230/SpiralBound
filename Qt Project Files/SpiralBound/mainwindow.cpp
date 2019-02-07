#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutspiralbound.h"
#include "addcalendarevent.h"
#include "deletecalendarevent.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>

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
// Init date:
// Last Updated:
void MainWindow::on_action_open_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_test_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_save_triggered()
{

}

// Author: Nicholas Ellis
// Init date: 29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_about_triggered()
{
    AboutSpiralBound dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author: Tyler Rogers
// Init date: 29.01.2019
// Last Updated: 29.01.2019
void MainWindow::on_action_aboutQt_triggered()
{
    QApplication::aboutQt();
}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_crashCourse_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_print_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_new_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_openRecent_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_saveAs_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_bold_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_italic_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_underline_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_comment_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_strikethrough_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_indent_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_unindent_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_bulletedList_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_numberedList_triggered()
{

}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_action_taskList_triggered()
{

}

// Author:
// Init date:
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
//               Calendar Buttons                            |
//-----------------------------------------------------------+

// Author: Nicholas, Cam, Jamie
// Init date: 05.02.2019
// Last Updated: 05.02.2019
void MainWindow::on_pushButton_addEvent_clicked()
{
    addcalendarevent dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author: Jamie, Nicholas
// Init date: 07.02.2019
// Last Updated: 07.02.20119
void MainWindow::on_pushButton_deleteEvent_clicked()
{
    deletecalendarevent dialogWindow;
    dialogWindow.setModal(true);
    dialogWindow.exec();
}

// Author:
// Init date:
// Last Updated:
void MainWindow::on_pushButton_editEvent_clicked()
{

}











