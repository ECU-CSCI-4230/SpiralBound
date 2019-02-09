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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_editcalendarevent
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *editcalendarevent)
    {
        if (editcalendarevent->objectName().isEmpty())
            editcalendarevent->setObjectName(QString::fromUtf8("editcalendarevent"));
        editcalendarevent->resize(400, 300);
        buttonBox = new QDialogButtonBox(editcalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(editcalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), editcalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), editcalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(editcalendarevent);
    } // setupUi

    void retranslateUi(QDialog *editcalendarevent)
    {
        editcalendarevent->setWindowTitle(QApplication::translate("editcalendarevent", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editcalendarevent: public Ui_editcalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCALENDAREVENT_H
