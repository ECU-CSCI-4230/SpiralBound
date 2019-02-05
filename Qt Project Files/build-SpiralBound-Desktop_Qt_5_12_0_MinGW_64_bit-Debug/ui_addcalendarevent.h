/********************************************************************************
** Form generated from reading UI file 'addcalendarevent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCALENDAREVENT_H
#define UI_ADDCALENDAREVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_addcalendarevent
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_eventName;
    QLabel *label_eventName;
    QLabel *label_eventDate;
    QLineEdit *lineEdit_eventDate;
    QLabel *label_eventDate_2;
    QLabel *label_eventTime;
    QLineEdit *lineEdit_eventTime;
    QLabel *label_eventTime_2;
    QLabel *label_eventName_2;

    void setupUi(QDialog *addcalendarevent)
    {
        if (addcalendarevent->objectName().isEmpty())
            addcalendarevent->setObjectName(QString::fromUtf8("addcalendarevent"));
        addcalendarevent->resize(447, 230);
        buttonBox = new QDialogButtonBox(addcalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 180, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_eventName = new QLineEdit(addcalendarevent);
        lineEdit_eventName->setObjectName(QString::fromUtf8("lineEdit_eventName"));
        lineEdit_eventName->setGeometry(QRect(100, 10, 331, 24));
        label_eventName = new QLabel(addcalendarevent);
        label_eventName->setObjectName(QString::fromUtf8("label_eventName"));
        label_eventName->setGeometry(QRect(20, 10, 80, 20));
        label_eventDate = new QLabel(addcalendarevent);
        label_eventDate->setObjectName(QString::fromUtf8("label_eventDate"));
        label_eventDate->setGeometry(QRect(20, 70, 80, 20));
        lineEdit_eventDate = new QLineEdit(addcalendarevent);
        lineEdit_eventDate->setObjectName(QString::fromUtf8("lineEdit_eventDate"));
        lineEdit_eventDate->setGeometry(QRect(100, 70, 331, 24));
        label_eventDate_2 = new QLabel(addcalendarevent);
        label_eventDate_2->setObjectName(QString::fromUtf8("label_eventDate_2"));
        label_eventDate_2->setGeometry(QRect(100, 100, 111, 20));
        label_eventTime = new QLabel(addcalendarevent);
        label_eventTime->setObjectName(QString::fromUtf8("label_eventTime"));
        label_eventTime->setGeometry(QRect(20, 130, 80, 20));
        lineEdit_eventTime = new QLineEdit(addcalendarevent);
        lineEdit_eventTime->setObjectName(QString::fromUtf8("lineEdit_eventTime"));
        lineEdit_eventTime->setGeometry(QRect(100, 130, 331, 24));
        label_eventTime_2 = new QLabel(addcalendarevent);
        label_eventTime_2->setObjectName(QString::fromUtf8("label_eventTime_2"));
        label_eventTime_2->setGeometry(QRect(100, 160, 111, 20));
        label_eventName_2 = new QLabel(addcalendarevent);
        label_eventName_2->setObjectName(QString::fromUtf8("label_eventName_2"));
        label_eventName_2->setGeometry(QRect(100, 40, 111, 20));

        retranslateUi(addcalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), addcalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addcalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(addcalendarevent);
    } // setupUi

    void retranslateUi(QDialog *addcalendarevent)
    {
        addcalendarevent->setWindowTitle(QApplication::translate("addcalendarevent", "Dialog", nullptr));
        label_eventName->setText(QApplication::translate("addcalendarevent", "Event Name", nullptr));
        label_eventDate->setText(QApplication::translate("addcalendarevent", "Event Date", nullptr));
        label_eventDate_2->setText(QApplication::translate("addcalendarevent", "Ex: MM/DD/YYYY", nullptr));
        label_eventTime->setText(QApplication::translate("addcalendarevent", "Event Time", nullptr));
        label_eventTime_2->setText(QApplication::translate("addcalendarevent", "Ex: HH:MM", nullptr));
        label_eventName_2->setText(QApplication::translate("addcalendarevent", "Ex: Homework 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcalendarevent: public Ui_addcalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCALENDAREVENT_H
