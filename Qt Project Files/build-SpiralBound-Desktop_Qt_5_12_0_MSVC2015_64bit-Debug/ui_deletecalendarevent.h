/********************************************************************************
** Form generated from reading UI file 'deletecalendarevent.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECALENDAREVENT_H
#define UI_DELETECALENDAREVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_deletecalendarevent
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *deletecalendarevent)
    {
        if (deletecalendarevent->objectName().isEmpty())
            deletecalendarevent->setObjectName(QString::fromUtf8("deletecalendarevent"));
        deletecalendarevent->resize(400, 300);
        buttonBox = new QDialogButtonBox(deletecalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(deletecalendarevent);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 120, 91, 20));

        retranslateUi(deletecalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), deletecalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deletecalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(deletecalendarevent);
    } // setupUi

    void retranslateUi(QDialog *deletecalendarevent)
    {
        deletecalendarevent->setWindowTitle(QApplication::translate("deletecalendarevent", "Delete Event", nullptr));
        label->setText(QApplication::translate("deletecalendarevent", "Are you sure?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deletecalendarevent: public Ui_deletecalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECALENDAREVENT_H
