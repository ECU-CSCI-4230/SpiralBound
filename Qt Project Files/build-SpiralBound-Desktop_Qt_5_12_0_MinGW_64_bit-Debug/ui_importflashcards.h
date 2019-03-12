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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_importflashcards
{
public:
    QGridLayout *gridLayout;
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
        gridLayout = new QGridLayout(importflashcards);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_path = new QLabel(importflashcards);
        label_path->setObjectName(QString::fromUtf8("label_path"));
        label_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_path, 1, 0, 1, 1);

        pushButton_import = new QPushButton(importflashcards);
        pushButton_import->setObjectName(QString::fromUtf8("pushButton_import"));

        gridLayout->addWidget(pushButton_import, 2, 0, 1, 2);

        pushButton_cancel = new QPushButton(importflashcards);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        gridLayout->addWidget(pushButton_cancel, 2, 2, 1, 2);

        label_selectedPath = new QLabel(importflashcards);
        label_selectedPath->setObjectName(QString::fromUtf8("label_selectedPath"));

        gridLayout->addWidget(label_selectedPath, 1, 1, 1, 3);

        pushButton_browse = new QPushButton(importflashcards);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));

        gridLayout->addWidget(pushButton_browse, 0, 0, 1, 4);


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
