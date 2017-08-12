#-------------------------------------------------
#
# Project created by QtCreator 2017-03-09T11:04:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DelegateEx
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datedelegate.cpp \
    comboboxdelegate.cpp \
    spinboxdelegate.cpp

HEADERS  += mainwindow.h \
    datedelegate.h \
    comboboxdelegate.h \
    spinboxdelegate.h
