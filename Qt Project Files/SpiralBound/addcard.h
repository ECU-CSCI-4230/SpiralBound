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

private:
    Ui::addcard *ui;
};

#endif // ADDCARD_H
