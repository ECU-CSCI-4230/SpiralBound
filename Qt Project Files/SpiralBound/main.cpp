#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    // Sets fonts, windows, etc. to a consistent size across platforms
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    QString facts[100] = {
        "Farts have been clocked at a speed of 10 feet per second",
        "Donkeys kill more people annually than plane crashes",
        "On an average work day, a typist’s figures travel 126 miles",
        "The longest recorded flight of a chicken is thirteen seconds",
        "40,000 Americans are injured by toilets each year",
        "Banging your head against a wall uses 150 calories a hour",
        "Vending Machines Kill More People per year than sharks",
        "There are three golf balls sitting on the moon!",
        "Like fingerprints, everyone's tongue print is different",
        "Butterflies taste with their feet",
        "In France, it is legal to marry a dead person",
        "To produce a single pound of honey, a single bee would have to visit 2 million flowers",
        "You are born with 300 bones, by the time you are an adult you will have 206",
        "A cockroach will live for weeks without its head before it starves to death",
        "A pig's orgasm lasts 30 minutes",
        "No word in the English language rhymes with month, orange, silver or purple",
        "In Tokyo, a bicycle is faster than a car for most trips of less than 50 minutes!",
        "An ostrich’s eye is bigger than its brain",
        "Every year, kids in North America spend close to half a billion dollars on chewing gum!",
        "Ketchup was sold in the 1830s as medicine",
        "The electric chair was invented by a dentist",
        "Donald Duck comics were banned from Finland because he doesn’t wear trousers",
        "The average lead pencil will draw a line 35 miles long or write approximately 50,000 English words",
        "The word pencil comes from a Latin word meaning small penis",
        "There is a French company that you can hire to kidnap you They charge US$1600",
        "Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch is the official name of a village in Wales",
        "It takes more calories to eat a piece of celery than the celery has in it",
        "Every day more money is printed for monopoly than the US Treasury",
        "Cost of raising a medium-sized dog to the age of 11: $5500",
        "Coca Cola was originally green",
        "Elephants are the only mammals that can't jump",
        "A rat can last longer without water than a camel",
        "It's possible to lead a cow upstairsbut not downstairs",
        "Every time you lick a stamp, you're consuming 1/10 of a calorie",
        "There are no clocks in Las Vegas gambling casinos!",
        "You are about 1 centimeter taller in the morning than in the evening!",
        "In India, people are legally allowed to marry a dog!",
        "More than 6,000 people with pillow-related injuries check into US emergency rooms every year!",
        "In Florida, It is illegal to sing in a public place while attired in a swimsuit",
        "A sneeze travels out your mouth at over 100 mph!",
        "A Boeing 747 airliner holds 57,285 gallons of fuel!",
        "A broken clock is right two times a day",
        "Every second, Americans collectively eat one hundred pounds of chocolate",
        "Every 45 seconds, a house catches on fire in the United States!",
        "The only 15 letter word that can be spelled without repeating a letter is \"uncopyrightable\"!",
        "1% of Germany's population is genetically immune to HIV",
        "You breathe on average about 5 million times a year",
        "It is impossible to sneeze with your eyes open",
        "Peanuts are one of the ingredients of dynamite",
        "German chocolate cake is named after a guy named Sam German, not the country.",
        "Wombat poop is cube-shaped.",
        "A \"buttload\" is a real measurement of weight.",
        "Cows have \"best friends\" and get stressed when separated.",
        "Ketchup was sold as medicine in the 1830s.",
        "A cat co-authored a physics paper in 1975.",
        "Baby puffins are called pufflings.",
        "Lego is the largest tire manufacturer in the world.",
        "All mammals take about 12 seconds to poop, regardless of size."
    };

    int rand = QRandomGenerator::global()->bounded(57);

    // Code for splash screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/SpiralBound/images/image0.png"));
    splash->show();

    splash->showMessage(facts[rand], Qt::AlignLeft,Qt::yellow);
    qApp->processEvents();

    MainWindow w;

    QTimer::singleShot(5000, splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));
    // w.show();
    return a.exec();
}
