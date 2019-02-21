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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_test;
    QAction *action_save;
    QAction *action_about;
    QAction *action_aboutQt;
    QAction *action_crashCourse;
    QAction *action_print;
    QAction *action_new;
    QAction *action_openRecent;
    QAction *action_saveAs;
    QAction *action_bold;
    QAction *action_italic;
    QAction *action_underline;
    QAction *action_comment;
    QAction *action_strikethrough;
    QAction *action_indent;
    QAction *action_unindent;
    QAction *action_bulletedList;
    QAction *action_numberedList;
    QAction *action_taskList;
    QAction *action_preferences;
    QAction *action_printPreview;
    QAction *action_export;
    QAction *action_quit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTableWidget *tableWidget_eventList;
    QPushButton *pushButton_addEvent;
    QPushButton *pushButton_editEvent;
    QPushButton *pushButton_deleteEvent;
    QPushButton *pushButton_printEventList;
    QCalendarWidget *calendarWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QLabel *label_cards;
    QPushButton *pushButton_studyDeck;
    QPushButton *pushButton_deleteDeck;
    QPushButton *pushButton_addDeck;
    QLabel *label_decks;
    QListWidget *listWidget_deckList;
    QTableWidget *tableWidget_cardsTable;
    QMenuBar *menuBar;
    QMenu *menuFile;
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
        MainWindow->resize(943, 642);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SpiralBound/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_test = new QAction(MainWindow);
        action_test->setObjectName(QString::fromUtf8("action_test"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        action_aboutQt = new QAction(MainWindow);
        action_aboutQt->setObjectName(QString::fromUtf8("action_aboutQt"));
        action_crashCourse = new QAction(MainWindow);
        action_crashCourse->setObjectName(QString::fromUtf8("action_crashCourse"));
        action_print = new QAction(MainWindow);
        action_print->setObjectName(QString::fromUtf8("action_print"));
        action_new = new QAction(MainWindow);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        action_openRecent = new QAction(MainWindow);
        action_openRecent->setObjectName(QString::fromUtf8("action_openRecent"));
        action_saveAs = new QAction(MainWindow);
        action_saveAs->setObjectName(QString::fromUtf8("action_saveAs"));
        action_bold = new QAction(MainWindow);
        action_bold->setObjectName(QString::fromUtf8("action_bold"));
        action_italic = new QAction(MainWindow);
        action_italic->setObjectName(QString::fromUtf8("action_italic"));
        action_underline = new QAction(MainWindow);
        action_underline->setObjectName(QString::fromUtf8("action_underline"));
        action_comment = new QAction(MainWindow);
        action_comment->setObjectName(QString::fromUtf8("action_comment"));
        action_strikethrough = new QAction(MainWindow);
        action_strikethrough->setObjectName(QString::fromUtf8("action_strikethrough"));
        action_indent = new QAction(MainWindow);
        action_indent->setObjectName(QString::fromUtf8("action_indent"));
        action_unindent = new QAction(MainWindow);
        action_unindent->setObjectName(QString::fromUtf8("action_unindent"));
        action_bulletedList = new QAction(MainWindow);
        action_bulletedList->setObjectName(QString::fromUtf8("action_bulletedList"));
        action_numberedList = new QAction(MainWindow);
        action_numberedList->setObjectName(QString::fromUtf8("action_numberedList"));
        action_taskList = new QAction(MainWindow);
        action_taskList->setObjectName(QString::fromUtf8("action_taskList"));
        action_preferences = new QAction(MainWindow);
        action_preferences->setObjectName(QString::fromUtf8("action_preferences"));
        action_printPreview = new QAction(MainWindow);
        action_printPreview->setObjectName(QString::fromUtf8("action_printPreview"));
        action_export = new QAction(MainWindow);
        action_export->setObjectName(QString::fromUtf8("action_export"));
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        tableWidget_eventList = new QTableWidget(tab_2);
        if (tableWidget_eventList->columnCount() < 3)
            tableWidget_eventList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_eventList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_eventList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_eventList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_eventList->setObjectName(QString::fromUtf8("tableWidget_eventList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_eventList->sizePolicy().hasHeightForWidth());
        tableWidget_eventList->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        tableWidget_eventList->setFont(font1);
        tableWidget_eventList->setAutoFillBackground(false);
        tableWidget_eventList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_eventList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_eventList->setAutoScrollMargin(16);
        tableWidget_eventList->setShowGrid(true);
        tableWidget_eventList->setGridStyle(Qt::DotLine);
        tableWidget_eventList->setSortingEnabled(true);
        tableWidget_eventList->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_eventList->horizontalHeader()->setDefaultSectionSize(147);
        tableWidget_eventList->horizontalHeader()->setMinimumSectionSize(5);
        tableWidget_eventList->horizontalHeader()->setStretchLastSection(false);
        tableWidget_eventList->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout_2->addWidget(tableWidget_eventList, 1, 1, 1, 1);

        pushButton_addEvent = new QPushButton(tab_2);
        pushButton_addEvent->setObjectName(QString::fromUtf8("pushButton_addEvent"));

        gridLayout_2->addWidget(pushButton_addEvent, 2, 1, 1, 1);

        pushButton_editEvent = new QPushButton(tab_2);
        pushButton_editEvent->setObjectName(QString::fromUtf8("pushButton_editEvent"));

        gridLayout_2->addWidget(pushButton_editEvent, 3, 1, 1, 1);

        pushButton_deleteEvent = new QPushButton(tab_2);
        pushButton_deleteEvent->setObjectName(QString::fromUtf8("pushButton_deleteEvent"));

        gridLayout_2->addWidget(pushButton_deleteEvent, 4, 1, 1, 1);

        pushButton_printEventList = new QPushButton(tab_2);
        pushButton_printEventList->setObjectName(QString::fromUtf8("pushButton_printEventList"));

        gridLayout_2->addWidget(pushButton_printEventList, 5, 1, 1, 1);

        calendarWidget = new QCalendarWidget(tab_2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(calendarWidget, 1, 0, 5, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_cards = new QLabel(tab_3);
        label_cards->setObjectName(QString::fromUtf8("label_cards"));
        label_cards->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_cards, 0, 1, 1, 1);

        pushButton_studyDeck = new QPushButton(tab_3);
        pushButton_studyDeck->setObjectName(QString::fromUtf8("pushButton_studyDeck"));

        gridLayout_5->addWidget(pushButton_studyDeck, 4, 0, 1, 1);

        pushButton_deleteDeck = new QPushButton(tab_3);
        pushButton_deleteDeck->setObjectName(QString::fromUtf8("pushButton_deleteDeck"));

        gridLayout_5->addWidget(pushButton_deleteDeck, 3, 0, 1, 1);

        pushButton_addDeck = new QPushButton(tab_3);
        pushButton_addDeck->setObjectName(QString::fromUtf8("pushButton_addDeck"));

        gridLayout_5->addWidget(pushButton_addDeck, 2, 0, 1, 1);

        label_decks = new QLabel(tab_3);
        label_decks->setObjectName(QString::fromUtf8("label_decks"));
        label_decks->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_decks, 0, 0, 1, 1);

        listWidget_deckList = new QListWidget(tab_3);
        listWidget_deckList->setObjectName(QString::fromUtf8("listWidget_deckList"));

        gridLayout_5->addWidget(listWidget_deckList, 1, 0, 1, 1);

        tableWidget_cardsTable = new QTableWidget(tab_3);
        if (tableWidget_cardsTable->columnCount() < 2)
            tableWidget_cardsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_cardsTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_cardsTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidget_cardsTable->setObjectName(QString::fromUtf8("tableWidget_cardsTable"));
        tableWidget_cardsTable->setColumnCount(2);
        tableWidget_cardsTable->horizontalHeader()->setDefaultSectionSize(220);
        tableWidget_cardsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_5->addWidget(tableWidget_cardsTable, 1, 1, 3, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 943, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
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

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFormat->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_new);
        menuFile->addAction(action_open);
        menuFile->addAction(action_openRecent);
        menuFile->addSeparator();
        menuFile->addAction(action_save);
        menuFile->addAction(action_saveAs);
        menuFile->addSeparator();
        menuFile->addAction(action_printPreview);
        menuFile->addAction(action_print);
        menuFile->addSeparator();
        menuFile->addAction(action_export);
        menuFile->addSeparator();
        menuFile->addAction(action_quit);
        menuEdit->addAction(action_test);
        menuFormat->addAction(action_bold);
        menuFormat->addAction(action_italic);
        menuFormat->addAction(action_underline);
        menuFormat->addAction(action_strikethrough);
        menuFormat->addAction(action_comment);
        menuFormat->addSeparator();
        menuFormat->addAction(action_indent);
        menuFormat->addAction(action_unindent);
        menuFormat->addSeparator();
        menuFormat->addAction(action_bulletedList);
        menuFormat->addAction(action_numberedList);
        menuFormat->addAction(action_taskList);
        menuSettings->addAction(action_preferences);
        menuHelp->addAction(action_crashCourse);
        menuHelp->addAction(action_about);
        menuHelp->addAction(action_aboutQt);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SprialBound", nullptr));
        action_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        action_test->setText(QApplication::translate("MainWindow", "Test", nullptr));
        action_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        action_about->setText(QApplication::translate("MainWindow", "About", nullptr));
        action_aboutQt->setText(QApplication::translate("MainWindow", "About Qt", nullptr));
        action_crashCourse->setText(QApplication::translate("MainWindow", "Crash Course", nullptr));
        action_print->setText(QApplication::translate("MainWindow", "Print", nullptr));
        action_new->setText(QApplication::translate("MainWindow", "New", nullptr));
        action_openRecent->setText(QApplication::translate("MainWindow", "Open Recent", nullptr));
        action_saveAs->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        action_bold->setText(QApplication::translate("MainWindow", "Bold", nullptr));
        action_italic->setText(QApplication::translate("MainWindow", "Italic", nullptr));
        action_underline->setText(QApplication::translate("MainWindow", "Underline", nullptr));
        action_comment->setText(QApplication::translate("MainWindow", "Comment", nullptr));
        action_strikethrough->setText(QApplication::translate("MainWindow", "Strikethrough", nullptr));
        action_indent->setText(QApplication::translate("MainWindow", "Indent", nullptr));
        action_unindent->setText(QApplication::translate("MainWindow", "Unindent", nullptr));
        action_bulletedList->setText(QApplication::translate("MainWindow", "Bulleted List", nullptr));
        action_numberedList->setText(QApplication::translate("MainWindow", "Numbered List", nullptr));
        action_taskList->setText(QApplication::translate("MainWindow", "Task List", nullptr));
        action_preferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        action_printPreview->setText(QApplication::translate("MainWindow", "Print Preview", nullptr));
        action_export->setText(QApplication::translate("MainWindow", "Export", nullptr));
        action_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "TextEditor", nullptr));
        label->setText(QApplication::translate("MainWindow", "Events List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_eventList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_eventList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_eventList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Time", nullptr));
        pushButton_addEvent->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButton_editEvent->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_deleteEvent->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_printEventList->setText(QApplication::translate("MainWindow", "Print (Debug)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Calendar", nullptr));
        label_cards->setText(QApplication::translate("MainWindow", "Cards", nullptr));
        pushButton_studyDeck->setText(QApplication::translate("MainWindow", "Study", nullptr));
        pushButton_deleteDeck->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_addDeck->setText(QApplication::translate("MainWindow", "Add", nullptr));
        label_decks->setText(QApplication::translate("MainWindow", "Decks", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_cardsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_cardsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Body", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Flash Cards", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
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
