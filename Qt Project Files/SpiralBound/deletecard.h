#ifndef DELETECARD_H
#define DELETECARD_H

#include <QDialog>

namespace Ui {
class deletecard;
}

class deletecard : public QDialog
{
    Q_OBJECT

public:
    explicit deletecard(QWidget *parent = nullptr);
    ~deletecard();

private slots:
    void on_buttonBox_accepted();

signals:
    // Send deletecalendarevent data to mainwindow
    void sendDeleteData(bool);

private:
    Ui::deletecard *ui;
};

#endif // DELETECARD_H
