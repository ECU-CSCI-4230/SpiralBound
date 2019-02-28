#ifndef ADDCALENDAREVENT_H
#define ADDCALENDAREVENT_H

#include <QDialog>

namespace Ui {
class addcalendarevent;
}

class addcalendarevent : public QDialog
{
    Q_OBJECT

public:
    explicit addcalendarevent(const QDate initDate, QWidget *parent = nullptr);
    ~addcalendarevent();

private slots:
    void on_buttonBox_accepted();

signals:
    // Send addcalendarevent data to mainwindow
    void sendAddData(QString, QString);


private:
    Ui::addcalendarevent *ui;
};

#endif // ADDCALENDAREVENT_H
