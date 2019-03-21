# Run this file using the MinGW terminal in the start menu for QT

qmake -project "QT += testlib core gui widgets"

qmake
mingw32-make
