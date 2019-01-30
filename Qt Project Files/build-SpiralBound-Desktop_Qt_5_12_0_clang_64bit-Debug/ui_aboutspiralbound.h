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
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutSpiralBound
{
public:
    QPushButton *pushButton_ok;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;

    void setupUi(QDialog *AboutSpiralBound)
    {
        if (AboutSpiralBound->objectName().isEmpty())
            AboutSpiralBound->setObjectName(QString::fromUtf8("AboutSpiralBound"));
        AboutSpiralBound->resize(402, 259);
        pushButton_ok = new QPushButton(AboutSpiralBound);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(160, 230, 80, 24));
        textBrowser = new QTextBrowser(AboutSpiralBound);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(70, 20, 311, 191));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);
        textBrowser_2 = new QTextBrowser(AboutSpiralBound);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 20, 61, 21));
        textBrowser_2->setFrameShape(QFrame::NoFrame);
        textBrowser_2->setFrameShadow(QFrame::Plain);

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
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">SpiralBound</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SpiralBound is an open source digital notebook and planner. It combines aspects from note taking and calendar applications. On top of this it incorporates study tools to aid"
                        " you in your learning process.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("AboutSpiralBound", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">&lt;LOGO&gt;</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutSpiralBound: public Ui_AboutSpiralBound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSPIRALBOUND_H
