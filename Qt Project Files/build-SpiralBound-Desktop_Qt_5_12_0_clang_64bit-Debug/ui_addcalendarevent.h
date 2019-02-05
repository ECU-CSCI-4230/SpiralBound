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

QT_BEGIN_NAMESPACE

class Ui_addcalendarevent
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *addcalendarevent)
    {
        if (addcalendarevent->objectName().isEmpty())
            addcalendarevent->setObjectName(QString::fromUtf8("addcalendarevent"));
        addcalendarevent->resize(447, 300);
        buttonBox = new QDialogButtonBox(addcalendarevent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(addcalendarevent);
        QObject::connect(buttonBox, SIGNAL(accepted()), addcalendarevent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addcalendarevent, SLOT(reject()));

        QMetaObject::connectSlotsByName(addcalendarevent);
    } // setupUi

    void retranslateUi(QDialog *addcalendarevent)
    {
        addcalendarevent->setWindowTitle(QApplication::translate("addcalendarevent", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcalendarevent: public Ui_addcalendarevent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCALENDAREVENT_H
