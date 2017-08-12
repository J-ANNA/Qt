#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T14:50:14
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeSever
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    timethread.cpp \
    timeserver.cpp

HEADERS  += dialog.h \
    timethread.h \
    timeserver.h
