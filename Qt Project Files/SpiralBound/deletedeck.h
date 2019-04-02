#ifndef DELETEDECK_H
#define DELETEDECK_H

#include <QDialog>

namespace Ui {
class deletedeck;
}

class deletedeck : public QDialog
{
    Q_OBJECT

public:
    explicit deletedeck(QWidget *parent = nullptr);
    ~deletedeck();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

signals:
    void sendDeleteData(bool);

private:
    Ui::deletedeck *ui;
};

#endif // DELETEDECK_H
