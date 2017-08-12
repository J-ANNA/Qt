#-------------------------------------------------
#
# Project created by QtCreator 2017-03-07T09:58:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsItem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flashitem.cpp \
    staritem.cpp

HEADERS  += mainwindow.h \
    flashitem.h \
    staritem.h

RESOURCES += \
    picture/str.qrc \
    str2.qrc
