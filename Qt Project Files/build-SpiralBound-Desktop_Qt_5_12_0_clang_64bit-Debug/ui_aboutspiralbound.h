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
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutSpiralBound
{
public:
    QPushButton *pushButton_ok;
    QTextBrowser *textBrowser;
    QLabel *label_logo;

    void setupUi(QDialog *AboutSpiralBound)
    {
        if (AboutSpiralBound->objectName().isEmpty())
            AboutSpiralBound->setObjectName(QString::fromUtf8("AboutSpiralBound"));
        AboutSpiralBound->resize(402, 259);
        AboutSpiralBound->setModal(false);
        pushButton_ok = new QPushButton(AboutSpiralBound);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(190, 230, 91, 24));
        textBrowser = new QTextBrowser(AboutSpiralBound);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(110, 20, 251, 192));
        label_logo = new QLabel(AboutSpiralBound);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(20, 20, 71, 61));
        label_logo->setTextFormat(Qt::RichText);
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/SpiralBound/images/icon.png")));
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignCenter);
        textBrowser->raise();
        pushButton_ok->raise();
        label_logo->raise();

        retranslateUi(AboutSpiralBound);

        QMetaObject::connectSlotsByName(AboutSpiralBound);
    } // setupUi

    void retranslateUi(QDialog *AboutSpiralBound)
    {
        AboutSpiralBound->setWindowTitle(QApplication::translate("AboutSpiralBound", "About SpiralBound", nullptr));
        pushButton_ok->setText(QApplication::translate("AboutSpiralBound", "Ok", nullptr));
        textBrowser->setHtml(QApplication::translate("AboutSpiralBound", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">SpiralBound </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Is an open source digital notebook and planner. It combines aspects from note taking and calendar applications. On top of this it incorporates study tools to aid you in your learning process.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragra"
                        "ph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutSpiralBound: public Ui_AboutSpiralBound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSPIRALBOUND_H
