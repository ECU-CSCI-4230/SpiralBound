#include "mainwindow.h"
#include "ui_mainwindow.h"
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

// Actions


void MainWindow::on_action_open_triggered()
{

}


void MainWindow::on_action_test_triggered()
{

}


void MainWindow::on_action_save_triggered()
{

}

void MainWindow::on_action_about_triggered()
{

}

void MainWindow::on_action_aboutQt_triggered()
{

}

void MainWindow::on_action_crashCourse_triggered()
{

}

void MainWindow::on_action_print_triggered()
{

}

void MainWindow::on_action_new_triggered()
{

}

void MainWindow::on_action_openRecent_triggered()
{

}

void MainWindow::on_action_saveAs_triggered()
{

}

void MainWindow::on_action_bold_triggered()
{

}

void MainWindow::on_action_italic_triggered()
{

}

void MainWindow::on_action_underline_triggered()
{

}

void MainWindow::on_action_comment_triggered()
{

}

void MainWindow::on_action_strikethrough_triggered()
{

}

void MainWindow::on_action_indent_triggered()
{

}

void MainWindow::on_action_unindent_triggered()
{

}

void MainWindow::on_action_bulletedList_triggered()
{

}

void MainWindow::on_action_numberedList_triggered()
{

}

void MainWindow::on_action_taskList_triggered()
{

}

void MainWindow::on_action_preferences_triggered()
{

}

void MainWindow::on_action_printPreview_triggered()
{

}

void MainWindow::on_action_export_triggered()
{

}

void MainWindow::on_action_quit_triggered()
{

}
