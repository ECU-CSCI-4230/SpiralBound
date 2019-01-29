#include "mainwindow.h"
#include "ui_mainwindow.h"

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
void MainWindow::on_action_new_triggered()
{
    qInfo("action_new triggered");
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

void MainWindow::on_action_Preferences_triggered()
{

}

void MainWindow::on_action_printPreview_triggered()
{

}

void MainWindow::on_action_Export_triggered()
{

}

void MainWindow::on_action_Quit_triggered()
{
    close();
}
