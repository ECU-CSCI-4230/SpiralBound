#include "importflashcards.h"
#include "ui_importflashcards.h"
#include "mainwindow.h"
#include "QFileDialog"
#include "QFile"
#include "QMessageBox"
#include "QTextStream"
#include "QStandardItem"
#include "QString"
#include "QStandardPaths"

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

// Author:       Cam
// Init Date:    05.03.2019
// Last Updated: 13.03.2019
void importflashcards::on_pushButton_browse_clicked()
{
    // Open File Browser and select desired file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(QDir::homePath()),
                                                    tr("CSV File (*.csv)"));
    // Get file path, display to user
    ui->label_selectedPath->setText(fileName);

}

// Author:       Cam, Matthew
// Init Date:    05.03.2019
// Last Updated: 07.03.2019
void importflashcards::on_pushButton_import_clicked()
{
    // Get the path and set the delimiter to be used
    QString path = ui->label_selectedPath->text();

    // Read File path
    QFile file(ui->label_selectedPath->text());

    // If file can open
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString deckName = in.readLine(), front, back;

        // While the file is not at the end
        while(!in.atEnd()) {
            // Card format is <n>,<front>,<back>, where <n> specifies where to split the front/back from
            // As such, parse <n>, then remove '<n>,' from the string, then parse the front/back
            QString card = in.readLine();
            int ind = card.left(card.indexOf(',')).toInt();
            card = card.right(card.length()-card.indexOf(',')-1);
            emit sendCardData(deckName, card.left(ind), card.right(card.length()-ind-1));
        }

        // Close file
        file.close();
     }

    // Close window
    importflashcards::close();
}

// Author:       Cam
// Init Date:    05.03.2019
// Last Updated: 05.03.2019
void importflashcards::on_pushButton_cancel_clicked()
{
    // Closes the window
    importflashcards::close();
}

