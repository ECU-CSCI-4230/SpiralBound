/********************************************************************************
** Form generated from reading UI file 'addcard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARD_H
#define UI_ADDCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addcard
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_backName;
    QDialogButtonBox *buttonBox;
    QLabel *label_deckName;
    QLineEdit *lineEdit_deck;
    QTextEdit *textEdit_front;
    QTextEdit *textEdit_back;
    QLabel *label_frontName;

    void setupUi(QDialog *addcard)
    {
        if (addcard->objectName().isEmpty())
            addcard->setObjectName(QString::fromUtf8("addcard"));
        addcard->resize(400, 300);
        gridLayout_2 = new QGridLayout(addcard);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_backName = new QLabel(addcard);
        label_backName->setObjectName(QString::fromUtf8("label_backName"));
        label_backName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_backName, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(addcard);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 3, 1, 1, 2);

        label_deckName = new QLabel(addcard);
        label_deckName->setObjectName(QString::fromUtf8("label_deckName"));
        label_deckName->setLayoutDirection(Qt::LeftToRight);
        label_deckName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_deckName, 0, 0, 1, 1);

        lineEdit_deck = new QLineEdit(addcard);
        lineEdit_deck->setObjectName(QString::fromUtf8("lineEdit_deck"));

        gridLayout_2->addWidget(lineEdit_deck, 0, 1, 1, 3);

        textEdit_front = new QTextEdit(addcard);
        textEdit_front->setObjectName(QString::fromUtf8("textEdit_front"));

        gridLayout_2->addWidget(textEdit_front, 2, 0, 1, 2);

        textEdit_back = new QTextEdit(addcard);
        textEdit_back->setObjectName(QString::fromUtf8("textEdit_back"));

        gridLayout_2->addWidget(textEdit_back, 2, 2, 1, 2);

        label_frontName = new QLabel(addcard);
        label_frontName->setObjectName(QString::fromUtf8("label_frontName"));
        label_frontName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_frontName, 1, 0, 1, 2);


        retranslateUi(addcard);
        QObject::connect(buttonBox, SIGNAL(accepted()), addcard, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addcard, SLOT(reject()));

        QMetaObject::connectSlotsByName(addcard);
    } // setupUi

    void retranslateUi(QDialog *addcard)
    {
        addcard->setWindowTitle(QApplication::translate("addcard", "Dialog", nullptr));
        label_backName->setText(QApplication::translate("addcard", "Back", nullptr));
        label_deckName->setText(QApplication::translate("addcard", "Deck Name", nullptr));
        label_frontName->setText(QApplication::translate("addcard", "Front", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addcard: public Ui_addcard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARD_H
