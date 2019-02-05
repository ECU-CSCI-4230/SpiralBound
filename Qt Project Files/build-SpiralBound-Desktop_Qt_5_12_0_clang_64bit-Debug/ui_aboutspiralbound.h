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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutSpiralBound
{
public:
    QPushButton *pushButton_ok;
    QLabel *label_logo;
    QLabel *label;

    void setupUi(QDialog *AboutSpiralBound)
    {
        if (AboutSpiralBound->objectName().isEmpty())
            AboutSpiralBound->setObjectName(QString::fromUtf8("AboutSpiralBound"));
        AboutSpiralBound->resize(350, 200);
        AboutSpiralBound->setModal(false);
        pushButton_ok = new QPushButton(AboutSpiralBound);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(180, 160, 91, 24));
        label_logo = new QLabel(AboutSpiralBound);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(20, 20, 71, 61));
        label_logo->setTextFormat(Qt::RichText);
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/SpiralBound/images/icon.png")));
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignCenter);
        label = new QLabel(AboutSpiralBound);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 251, 131));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);

        retranslateUi(AboutSpiralBound);

        QMetaObject::connectSlotsByName(AboutSpiralBound);
    } // setupUi

    void retranslateUi(QDialog *AboutSpiralBound)
    {
        AboutSpiralBound->setWindowTitle(QApplication::translate("AboutSpiralBound", "About SpiralBound", nullptr));
        pushButton_ok->setText(QApplication::translate("AboutSpiralBound", "Ok", nullptr));
        label_logo->setText(QString());
        label->setText(QApplication::translate("AboutSpiralBound", "<html><head/><body><p>About Spiral Bound</p><p><span style=\" font-size:12pt;\">SpiralBound is an open source digital notebook and planner. It combines aspects from note taking and calendar applications. On top of this it incorporates study tools to aid you in your learning process.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutSpiralBound: public Ui_AboutSpiralBound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSPIRALBOUND_H
