######################################################################
# Automatically generated by qmake (3.1) Tue Feb 26 23:03:40 2019
######################################################################

QT += testlib
QT += core gui
QT += widgets
TEMPLATE = app
TARGET = SpiralBound
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        aboutspiralbound.cpp \
        addcalendarevent.cpp \
        deletecalendarevent.cpp \
        editcalendarevent.cpp \
        block.cpp \
        page.cpp \
        section.cpp \
        book.cpp \
        markdowneditor.cpp \
        addcard.cpp \
        deletecard.cpp \
        importflashcards.cpp

HEADERS += \
        mainwindow.h \
        aboutspiralbound.h \
        addcalendarevent.h \
        deletecalendarevent.h \
        editcalendarevent.h \
        block.h \
        page.h \
        section.h \
        book.h \
        util.h \
        unit_book.h \
        markdowneditor.h \
        addcard.h \
        deletecard.h \
        importflashcards.h

FORMS += \
        mainwindow.ui \
        aboutspiralbound.ui \
        addcalendarevent.ui \
        deletecalendarevent.ui \
        editcalendarevent.ui \
        addpage.ui \
        addcard.ui \
        deletecard.ui \
        importflashcards.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    spiralbound.qrc

DISTFILES +=
