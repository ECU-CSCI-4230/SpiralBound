#ifndef DELETECALENDAREVENT_H
#define DELETECALENDAREVENT_H

#include <QDialog>

namespace Ui {
class deletecalendarevent;
}

class deletecalendarevent : public QDialog
{
    Q_OBJECT

public:
    explicit deletecalendarevent(QWidget *parent = nullptr);
    ~deletecalendarevent();

private:
    Ui::deletecalendarevent *ui;
};

#endif // DELETECALENDAREVENT_H
