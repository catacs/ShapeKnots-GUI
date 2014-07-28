#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T19:24:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR = ../bin
TARGET = ShapeKnots-GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shapeknotsprocess.cpp \
    shapeknotsapp.cpp \
    drawprocess.cpp \
    configuration.cpp \
    appsettings.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    shapeknotsprocess.h \
    shapeknotsapp.h \
    drawprocess.h \
    configuration.h \
    appsettings.h \
    defines.h \
    about.h \
    appconstants.h

FORMS    += mainwindow.ui \
    configuration.ui \
    about.ui
ICON = /img/app.ico
RESOURCES += resources.qrc

TRANSLATIONS    +=  lang/lang_en.ts \
                    lang/lang_es.ts \
                    lang/lang_fr.ts \
                    lang/lang_ro.ts

