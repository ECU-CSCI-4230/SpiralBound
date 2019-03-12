#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <editcalendarevent.h>
#include <addcalendarevent.h>
#include <deletecalendarevent.h>
#include <addcard.h>
#include <importflashcards.h>
#include <deletecard.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Menu Bar Buttons
    void on_action_open_triggered();
    void on_action_test_triggered();
    void on_action_save_triggered();
    void on_action_about_triggered();
    void on_action_aboutQt_triggered();
    void on_action_crashCourse_triggered();
    void on_action_print_triggered();
    void on_action_new_triggered();
    void on_action_openRecent_triggered();
    void on_action_saveAs_triggered();
    void on_action_bold_triggered();
    void on_action_italic_triggered();
    void on_action_underline_triggered();
    void on_action_comment_triggered();
    void on_action_strikethrough_triggered();
    void on_action_indent_triggered();
    void on_action_unindent_triggered();
    void on_action_bulletedList_triggered();
    void on_action_numberedList_triggered();
    void on_action_taskList_triggered();
    void on_action_preferences_triggered();
    void on_action_printPreview_triggered();
    void on_action_export_triggered();
    void on_action_quit_triggered();

    //==================
    // Calendar Buttons
    //==================
    void on_pushButton_addEvent_clicked();
    void on_pushButton_deleteEvent_clicked();
    void on_pushButton_editEvent_clicked();
    void on_pushButton_printEventList_clicked();

    // Receive addcalendarevent data to mainwindow
    void receiveAddData(QString, QString);
    // Receive deletecalendarevent data to mainwindow
    void receiveDeleteData(bool);

    // Stretch tableWidget_eventList headers to fit window
    void stretchTableHeaders();

    //=========================
    // Flash Card Tool Buttons
    //=========================
    void on_pushButton_addCard_clicked();
    void on_pushButton_deleteCard_clicked();
    void on_pushButton_studyCard_clicked();
    void on_pushButton_import_clicked();

    // Receive addCard data to mainwindow
    void receiveCardData(QString, QString, QString);
    void receiveCardDeleteData(bool);


private:
    Ui::MainWindow *ui;
    QString file_path_;

    deletecalendarevent *deleteWindow;
    addcalendarevent *addWindow;
    editcalendarevent *editWindow;
    addcard *addCardWindow;
    importflashcards *importCardWindow;
    deletecard *deleteCardWindow;

};

#endif // MAINWINDOW_H
