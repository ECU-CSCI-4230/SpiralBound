#ifndef ADDBOOK_H
#define ADDBOOK_H
#include <QDate>
#include <QDialog>

namespace Ui {
class addbook;
}

class addbook : public QDialog
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();

private slots:
    void on_buttonBox_accepted();


signals:
    // Send data to mainWindow
    void sendBookData(QString,QString, QString);

private:
    Ui::addbook *ui;
};

#endif // ADDBOOK_H
