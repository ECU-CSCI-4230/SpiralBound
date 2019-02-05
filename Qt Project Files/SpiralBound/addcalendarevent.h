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
    explicit addcalendarevent(QWidget *parent = nullptr);
    ~addcalendarevent();

private:
    Ui::addcalendarevent *ui;
};

#endif // ADDCALENDAREVENT_H
