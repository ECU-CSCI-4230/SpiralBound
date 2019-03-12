/********************************************************************************
** Form generated from reading UI file 'importflashcards.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTFLASHCARDS_H
#define UI_IMPORTFLASHCARDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_importflashcards
{
public:
    QLabel *label_path;
    QPushButton *pushButton_import;
    QPushButton *pushButton_cancel;
    QLabel *label_selectedPath;
    QPushButton *pushButton_browse;

    void setupUi(QDialog *importflashcards)
    {
        if (importflashcards->objectName().isEmpty())
            importflashcards->setObjectName(QString::fromUtf8("importflashcards"));
        importflashcards->resize(400, 136);
        label_path = new QLabel(importflashcards);
        label_path->setObjectName(QString::fromUtf8("label_path"));
        label_path->setGeometry(QRect(11, 43, 31, 50));
        label_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_import = new QPushButton(importflashcards);
        pushButton_import->setObjectName(QString::fromUtf8("pushButton_import"));
        pushButton_import->setGeometry(QRect(11, 100, 185, 25));
        pushButton_cancel = new QPushButton(importflashcards);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(207, 100, 185, 25));
        label_selectedPath = new QLabel(importflashcards);
        label_selectedPath->setObjectName(QString::fromUtf8("label_selectedPath"));
        label_selectedPath->setGeometry(QRect(45, 43, 341, 50));
        pushButton_browse = new QPushButton(importflashcards);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));
        pushButton_browse->setGeometry(QRect(11, 11, 378, 25));

        retranslateUi(importflashcards);

        QMetaObject::connectSlotsByName(importflashcards);
    } // setupUi

    void retranslateUi(QDialog *importflashcards)
    {
        importflashcards->setWindowTitle(QApplication::translate("importflashcards", "Dialog", nullptr));
        label_path->setText(QApplication::translate("importflashcards", "Path:", nullptr));
        pushButton_import->setText(QApplication::translate("importflashcards", "Import", nullptr));
        pushButton_cancel->setText(QApplication::translate("importflashcards", "Cancel", nullptr));
        label_selectedPath->setText(QApplication::translate("importflashcards", "None", nullptr));
        pushButton_browse->setText(QApplication::translate("importflashcards", "Browse...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class importflashcards: public Ui_importflashcards {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTFLASHCARDS_H
