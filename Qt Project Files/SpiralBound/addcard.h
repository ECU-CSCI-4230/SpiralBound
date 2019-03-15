#ifndef ADDCARD_H
#define ADDCARD_H

#include <QDialog>

namespace Ui {
class addcard;
}

class addcard : public QDialog
{
    Q_OBJECT

public:
    explicit addcard(QWidget *parent = nullptr);
    ~addcard();

private slots:
    void on_buttonBox_accepted();

signals:
    // Send addcard data to mainwindow
    void sendCardData(QString,QString,QString);

private:
    Ui::addcard *ui;
};

#endif // ADDCARD_H
