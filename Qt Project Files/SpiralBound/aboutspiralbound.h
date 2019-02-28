#ifndef ABOUTSPIRALBOUND_H
#define ABOUTSPIRALBOUND_H

#include <QDialog>

namespace Ui {
class AboutSpiralBound;
}

class AboutSpiralBound : public QDialog
{
    Q_OBJECT

public:
    explicit AboutSpiralBound(QWidget *parent = nullptr);
    ~AboutSpiralBound();

private slots:
    void on_pushButton_ok_clicked();


private:
    Ui::AboutSpiralBound *ui;
};

#endif // ABOUTSPIRALBOUND_H
