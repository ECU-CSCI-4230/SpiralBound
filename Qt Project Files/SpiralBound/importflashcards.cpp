#include "importflashcards.h"
#include "ui_importflashcards.h"
#include "QFileDialog"
#include "QFile"
#include "QMessageBox"

importflashcards::importflashcards(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importflashcards)
{
    ui->setupUi(this);
}

importflashcards::~importflashcards()
{
    delete ui;
}

// Author: Cam
// Init Date: 05.03.2019
// Last Updated: 05.03.2019
void importflashcards::on_pushButton_browse_clicked()
{
    // Open File Browser and select desired file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("*"));
    // Get file path, display to user
    ui->label_selectedPath->setText(fileName);

}

// Author: Cam
// Init Date: 05.03.2019
// Last Updated: 05.03.2019
void importflashcards::on_pushButton_import_clicked()
{
    // Read File path

    // Parse through CSV file and add data to table

    // Parse through txt file and add data to table
}

// Author: Cam
// Init Date: 05.03.2019
// Last Updated: 05.03.2019
void importflashcards::on_pushButton_cancel_clicked()
{
    // Closes the window
    importflashcards::close();
}

