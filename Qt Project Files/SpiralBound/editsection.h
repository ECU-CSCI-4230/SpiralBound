#ifndef EDITSECTION_H
#define EDITSECTION_H

#include <QDialog>

namespace Ui {
class editsection;
}

class editsection : public QDialog
{
    Q_OBJECT

public:
    explicit editsection(QWidget *parent = nullptr);
    ~editsection();

signals:
    void sendSectionData(QString, QColor, int);

private:
    Ui::editsection *ui;
    int myIndex;
    QColor myCol;

private slots:
    void on_buttonBox_accepted();
    void on_pushButton_Color_clicked();

    void receiveSectionData(QString, QColor, int);
};

#endif // EDITSECTION_H
