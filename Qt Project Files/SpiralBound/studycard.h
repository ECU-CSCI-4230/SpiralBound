#ifndef STUDYCARD_H
#define STUDYCARD_H

#include <QDialog>
#include <QTableWidget>
#include <list>
#include <util.h>
#include <QListWidgetItem>

extern int x;

namespace Ui {
class studycard;
}

class studycard : public QDialog
{
    Q_OBJECT

public:
    std::list<QString> deck, front, back;
    explicit studycard(QWidget *parent = nullptr, Deck* deck = nullptr);
    ~studycard();


private slots:
    void on_pushButton_flip_clicked();

private:
    Ui::studycard *ui;
    int x;

};

#endif // STUDYCARD_H
