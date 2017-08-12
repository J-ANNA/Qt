#-------------------------------------------------
#
# Project created by QtCreator 2017-02-24T10:53:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Example1
TEMPLATE = app


SOURCES += main.cpp\
        example.cpp \
    baseinfo.cpp \
    contact.cpp \
    detail.cpp

HEADERS  += example.h \
    baseinfo.h \
    contact.h \
    detail.h

RESOURCES += \
    picture/src.qrc
