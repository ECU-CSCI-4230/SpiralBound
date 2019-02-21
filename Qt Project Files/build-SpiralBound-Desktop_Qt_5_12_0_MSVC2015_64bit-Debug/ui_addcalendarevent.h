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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
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
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *addcalendarevent)
    {
        if (addcalendarevent->objectName().isEmpty())
            addcalendarevent->setObjectName(QString::fromUtf8("addcalendarevent"));
        addcalendarevent->resize(447, 160);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SpiralBound/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addcalendarevent->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(addcalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit_eventName = new QLineEdit(addcalendarevent);
        lineEdit_eventName->setObjectName(QString::fromUtf8("lineEdit_eventName"));
        lineEdit_eventName->setGeometry(QRect(100, 20, 331, 24));
        label_eventName = new QLabel(addcalendarevent);
        label_eventName->setObjectName(QString::fromUtf8("label_eventName"));
        label_eventName->setGeometry(QRect(20, 20, 80, 20));
        label_eventDate = new QLabel(addcalendarevent);
        label_eventDate->setObjectName(QString::fromUtf8("label_eventDate"));
        label_eventDate->setGeometry(QRect(20, 70, 111, 20));
        dateTimeEdit = new QDateTimeEdit(addcalendarevent);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(130, 70, 301, 25));
        dateTimeEdit->setProperty("showGroupSeparator", QVariant(false));

        retranslateUi(addcalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), addcalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addcalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(addcalendarevent);
    } // setupUi

    void retranslateUi(QDialog *addcalendarevent)
    {
        addcalendarevent->setWindowTitle(QApplication::translate("addcalendarevent", "Add Calendar Event", nullptr));
        label_eventName->setText(QApplication::translate("addcalendarevent", "Event Name", nullptr));
        label_eventDate->setText(QApplication::translate("addcalendarevent", "Event Date/Time", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("addcalendarevent", "MM/dd/yyyy hh:mm AP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcalendarevent: public Ui_addcalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCALENDAREVENT_H
