#ifndef ADDDECK_H
#define ADDDECK_H

#include <QDialog>

namespace Ui {
class adddeck;
}

class adddeck : public QDialog
{
    Q_OBJECT

public:
    explicit adddeck(QWidget *parent = nullptr);
    ~adddeck();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    // Add deck to deck list
    void sendDeckData(QString);

private:
    Ui::adddeck *ui;
};

#endif // ADDDECK_H
