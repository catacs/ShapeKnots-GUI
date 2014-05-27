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
    appsettings.cpp

HEADERS  += mainwindow.h \
    shapeknotsprocess.h \
    shapeknotsapp.h \
    drawprocess.h \
    configuration.h \
    appsettings.h

FORMS    += mainwindow.ui \
    configuration.ui
