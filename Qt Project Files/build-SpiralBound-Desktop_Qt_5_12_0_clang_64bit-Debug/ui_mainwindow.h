/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionstes;
    QAction *actionTest;
    QAction *actionSave;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionCrash_Course;
    QAction *actionPrint;
    QAction *actionNew;
    QAction *actionOpen_Recent;
    QAction *actionSave_As;
    QAction *actionBold;
    QAction *actionItalic;
    QAction *actionUnderline;
    QAction *actionComment;
    QAction *actionStrikethrough;
    QAction *actionIndent;
    QAction *actionUnindent;
    QAction *actionBulleted_List;
    QAction *actionNumbered_List;
    QAction *actionTask_List;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QCalendarWidget *calendarWidget;
    QMenuBar *menuBar;
    QMenu *menutest;
    QMenu *menuEdit;
    QMenu *menuFormat;
    QMenu *menuView;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(936, 642);
        actionstes = new QAction(MainWindow);
        actionstes->setObjectName(QString::fromUtf8("actionstes"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QString::fromUtf8("actionTest"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionCrash_Course = new QAction(MainWindow);
        actionCrash_Course->setObjectName(QString::fromUtf8("actionCrash_Course"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen_Recent = new QAction(MainWindow);
        actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionUnderline = new QAction(MainWindow);
        actionUnderline->setObjectName(QString::fromUtf8("actionUnderline"));
        actionComment = new QAction(MainWindow);
        actionComment->setObjectName(QString::fromUtf8("actionComment"));
        actionStrikethrough = new QAction(MainWindow);
        actionStrikethrough->setObjectName(QString::fromUtf8("actionStrikethrough"));
        actionIndent = new QAction(MainWindow);
        actionIndent->setObjectName(QString::fromUtf8("actionIndent"));
        actionUnindent = new QAction(MainWindow);
        actionUnindent->setObjectName(QString::fromUtf8("actionUnindent"));
        actionBulleted_List = new QAction(MainWindow);
        actionBulleted_List->setObjectName(QString::fromUtf8("actionBulleted_List"));
        actionNumbered_List = new QAction(MainWindow);
        actionNumbered_List->setObjectName(QString::fromUtf8("actionNumbered_List"));
        actionTask_List = new QAction(MainWindow);
        actionTask_List->setObjectName(QString::fromUtf8("actionTask_List"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 10, 831, 521));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 10, 831, 501));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        calendarWidget = new QCalendarWidget(tab_2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 641, 331));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 936, 22));
        menutest = new QMenu(menuBar);
        menutest->setObjectName(QString::fromUtf8("menutest"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuFormat = new QMenu(menuBar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menutest->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFormat->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menutest->addAction(actionNew);
        menutest->addAction(actionstes);
        menutest->addAction(actionOpen_Recent);
        menutest->addSeparator();
        menutest->addAction(actionSave);
        menutest->addAction(actionSave_As);
        menutest->addSeparator();
        menutest->addAction(actionPrint);
        menuEdit->addAction(actionTest);
        menuFormat->addAction(actionBold);
        menuFormat->addAction(actionItalic);
        menuFormat->addAction(actionUnderline);
        menuFormat->addAction(actionStrikethrough);
        menuFormat->addAction(actionComment);
        menuFormat->addSeparator();
        menuFormat->addAction(actionIndent);
        menuFormat->addAction(actionUnindent);
        menuFormat->addSeparator();
        menuFormat->addAction(actionBulleted_List);
        menuFormat->addAction(actionNumbered_List);
        menuFormat->addAction(actionTask_List);
        menuSettings->addAction(actionPreferences);
        menuHelp->addAction(actionCrash_Course);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SprialBound", nullptr));
        actionstes->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionTest->setText(QApplication::translate("MainWindow", "Test", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", nullptr));
        actionCrash_Course->setText(QApplication::translate("MainWindow", "Crash Course", nullptr));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
        actionOpen_Recent->setText(QApplication::translate("MainWindow", "Open Recent", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionBold->setText(QApplication::translate("MainWindow", "Bold", nullptr));
        actionItalic->setText(QApplication::translate("MainWindow", "Italic", nullptr));
        actionUnderline->setText(QApplication::translate("MainWindow", "Underline", nullptr));
        actionComment->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        actionStrikethrough->setText(QApplication::translate("MainWindow", "Strikethrough", nullptr));
        actionIndent->setText(QApplication::translate("MainWindow", "Indent", nullptr));
        actionUnindent->setText(QApplication::translate("MainWindow", "Unindent", nullptr));
        actionBulleted_List->setText(QApplication::translate("MainWindow", "Bulleted List", nullptr));
        actionNumbered_List->setText(QApplication::translate("MainWindow", "Numbered List", nullptr));
        actionTask_List->setText(QApplication::translate("MainWindow", "Task List", nullptr));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "TextEditor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Calendar", nullptr));
        menutest->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuFormat->setTitle(QApplication::translate("MainWindow", "Format", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
