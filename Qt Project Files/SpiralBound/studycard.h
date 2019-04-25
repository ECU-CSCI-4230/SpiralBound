#ifndef STUDYCARD_H
#define STUDYCARD_H

#include <QDialog>
#include <QTableWidget>
#include <list>
#include <util.h>
#include <QListWidgetItem>

// extern int side;
// extern Deck* copyDeck;

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

    void on_pushButton_ok_clicked();

    void on_pushButton_previous_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::studycard *ui;
    int side = 0;
    int index = 0;
    Deck* copyDeck = nullptr;
};

#endif // STUDYCARD_H
