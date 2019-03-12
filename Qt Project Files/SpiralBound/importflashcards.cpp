#include "importflashcards.h"
#include "ui_importflashcards.h"
#include "mainwindow.h"
#include "QFileDialog"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QStandardItem"
#include "QString"

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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("*.csv *.txt"));
    // Get file path, display to user
    ui->label_selectedPath->setText(fileName);

}

// Author: Cam
// Init Date: 05.03.2019
// Last Updated: 07.03.2019
void importflashcards::on_pushButton_import_clicked()
{
    // Get the path
    QString path = ui->label_selectedPath->text();

    if(path.back() == 'v')     // File is a csv file
    {
        // Read File path
        QFile file(ui->label_selectedPath->text());

        // If file can open
        if (file.open(QIODevice::ReadOnly))
        {
            int index = 0;
            QString deckName, front, back;
            QTextStream in(&file);

            // While the file is not at the end
            while(!in.atEnd())
            {
                // Read one line at a time
                QString fileLine = in.readLine();

                // Parse through each value
                QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

                deckName = lineToken[0];
                front    = lineToken[1];
                back     = lineToken[2];

                // Send card data back to main window
                emit sendCardData(deckName, front, back);

                // Go to next line of file
                index++;
            }

            // Close file
            file.close();
         }

    }
    else if (path.back() == 't')    // File is a txt file
    {
        QFile file(ui->label_selectedPath->text());

        if (file.open(QIODevice::ReadOnly))
        {
            int index = 0;
            QString deckName, front, back;
            QTextStream in(&file);

            // While the file is not at the end
            while(!in.atEnd())
            {
                // Read one line at a time
                QString fileLine = in.readLine();

                // Parse through each value
                QStringList lineToken = fileLine.split("\t", QString::SkipEmptyParts);

                deckName = lineToken[0];
                front    = lineToken[1];
                back     = lineToken[2];

                // Send card data back to main window
                emit sendCardData(deckName, front, back);

                // Go to next line of file
                index++;
            }

            // Close file
            file.close();
         }
    }

    // Close window
    importflashcards::close();
}

// Author: Cam
// Init Date: 05.03.2019
// Last Updated: 05.03.2019
void importflashcards::on_pushButton_cancel_clicked()
{
    // Closes the window
    importflashcards::close();
}

