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

private:
    Ui::deletecard *ui;
};

#endif // DELETECARD_H
