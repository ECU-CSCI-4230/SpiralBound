/********************************************************************************
** Form generated from reading UI file 'editcalendarevent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCALENDAREVENT_H
#define UI_EDITCALENDAREVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_editcalendarevent
{
public:
    QDialogButtonBox *buttonBox;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_eventDate;
    QLabel *label_eventName;
    QLineEdit *lineEdit_eventName;

    void setupUi(QDialog *editcalendarevent)
    {
        if (editcalendarevent->objectName().isEmpty())
            editcalendarevent->setObjectName(QString::fromUtf8("editcalendarevent"));
        editcalendarevent->resize(447, 160);
        buttonBox = new QDialogButtonBox(editcalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        dateTimeEdit = new QDateTimeEdit(editcalendarevent);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(130, 70, 301, 25));
        label_eventDate = new QLabel(editcalendarevent);
        label_eventDate->setObjectName(QString::fromUtf8("label_eventDate"));
        label_eventDate->setGeometry(QRect(20, 70, 111, 20));
        label_eventName = new QLabel(editcalendarevent);
        label_eventName->setObjectName(QString::fromUtf8("label_eventName"));
        label_eventName->setGeometry(QRect(20, 20, 80, 20));
        lineEdit_eventName = new QLineEdit(editcalendarevent);
        lineEdit_eventName->setObjectName(QString::fromUtf8("lineEdit_eventName"));
        lineEdit_eventName->setGeometry(QRect(100, 20, 331, 24));

        retranslateUi(editcalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), editcalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), editcalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(editcalendarevent);
    } // setupUi

    void retranslateUi(QDialog *editcalendarevent)
    {
        editcalendarevent->setWindowTitle(QApplication::translate("editcalendarevent", "Edit Event", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("editcalendarevent", "MM/dd/yyyy hh:mm AP", nullptr));
        label_eventDate->setText(QApplication::translate("editcalendarevent", "Event Date/Time", nullptr));
        label_eventName->setText(QApplication::translate("editcalendarevent", "Event Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editcalendarevent: public Ui_editcalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCALENDAREVENT_H
