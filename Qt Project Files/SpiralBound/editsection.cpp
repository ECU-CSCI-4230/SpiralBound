#include "editsection.h"
#include "ui_editsection.h"
#include <QColorDialog>

editsection::editsection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editsection)
{
    ui->setupUi(this);
}

editsection::~editsection()
{
    delete ui;
}

// Author:       Matthew Morgan
// Init Date:    03-20-2019
// Last Updated: 03-20-2019
void editsection::receiveSectionData(QString qst, QColor qcol, int ind) {
    QPalette pal = ui->pushButton_Color->palette();
    pal.setColor(QPalette::Button, qcol);

    myIndex = ind;
    myCol = qcol;
    ui->lineEdit_Name->setText(qst);
    ui->pushButton_Color->setStyleSheet(QString("background-color: %1").arg(qcol.name()));
}

// Author:       Matthew Morgan
// Init Date:    03-20-2019
// Last Updated: 03-20-2019
void editsection::on_pushButton_Color_clicked() {
    QColor newCol = QColorDialog::getColor(myCol, this, "Select a Color");

    if (newCol.isValid()) {
        myCol = newCol;
        ui->pushButton_Color->setStyleSheet(QString("background-color: %1").arg(newCol.name()));
    }
}

// Author:       Matthew Morgan
// Init Date:    03-20-2019
// Last Updated: 03-20-2019
void editsection::on_buttonBox_accepted() {
    emit sendSectionData(ui->lineEdit_Name->text(), myCol, myIndex);
}
