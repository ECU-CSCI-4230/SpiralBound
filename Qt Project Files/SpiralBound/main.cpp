#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    // Sets fonts, windows, etc. to a consistent size across platforms
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    // Code for splash screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/SpiralBound/images/SplashScreen.png"));
    splash->show();

    MainWindow w;

    QTimer::singleShot(5000, splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));
    // w.show();
    return a.exec();
}
