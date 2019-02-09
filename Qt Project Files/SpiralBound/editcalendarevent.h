#ifndef EDITCALENDAREVENT_H
#define EDITCALENDAREVENT_H

#include <QDialog>

namespace Ui {
class editcalendarevent;
}

class editcalendarevent : public QDialog
{
    Q_OBJECT

public:
    explicit editcalendarevent(QWidget *parent = nullptr);
    ~editcalendarevent();

private:
    Ui::editcalendarevent *ui;
};

#endif // EDITCALENDAREVENT_H
