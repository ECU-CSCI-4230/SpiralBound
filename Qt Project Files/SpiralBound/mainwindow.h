#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qlistwidget.h>
#include <QListWidget>
#include <QMainWindow>

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

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString file_path_;
    Ui::MainWindow *ListWidget;

};

#endif // MAINWINDOW_H
