/********************************************************************************
** Form generated from reading UI file 'deletecard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETECARD_H
#define UI_DELETECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_deletecard
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *deletecard)
    {
        if (deletecard->objectName().isEmpty())
            deletecard->setObjectName(QString::fromUtf8("deletecard"));
        deletecard->resize(400, 108);
        buttonBox = new QDialogButtonBox(deletecard);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-55, 60, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(deletecard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 20, 101, 16));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(deletecard);
        QObject::connect(buttonBox, SIGNAL(accepted()), deletecard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deletecard, SLOT(reject()));

        QMetaObject::connectSlotsByName(deletecard);
    } // setupUi

    void retranslateUi(QDialog *deletecard)
    {
        deletecard->setWindowTitle(QApplication::translate("deletecard", "Dialog", nullptr));
        label->setText(QApplication::translate("deletecard", "Are you sure?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deletecard: public Ui_deletecard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETECARD_H
