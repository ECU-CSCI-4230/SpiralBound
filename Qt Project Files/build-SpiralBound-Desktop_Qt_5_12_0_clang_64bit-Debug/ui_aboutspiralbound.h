/********************************************************************************
** Form generated from reading UI file 'aboutspiralbound.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSPIRALBOUND_H
#define UI_ABOUTSPIRALBOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutSpiralBound
{
public:
    QPushButton *pushButton_ok;

    void setupUi(QDialog *AboutSpiralBound)
    {
        if (AboutSpiralBound->objectName().isEmpty())
            AboutSpiralBound->setObjectName(QString::fromUtf8("AboutSpiralBound"));
        AboutSpiralBound->resize(402, 259);
        pushButton_ok = new QPushButton(AboutSpiralBound);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(180, 230, 91, 24));

        retranslateUi(AboutSpiralBound);

        QMetaObject::connectSlotsByName(AboutSpiralBound);
    } // setupUi

    void retranslateUi(QDialog *AboutSpiralBound)
    {
        AboutSpiralBound->setWindowTitle(QApplication::translate("AboutSpiralBound", "About SpiralBound", nullptr));
        pushButton_ok->setText(QApplication::translate("AboutSpiralBound", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutSpiralBound: public Ui_AboutSpiralBound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSPIRALBOUND_H
