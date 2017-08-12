#-------------------------------------------------
#
# Project created by QtCreator 2017-03-01T08:21:09
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImgProcessor
TEMPLATE = app


SOURCES += main.cpp\
        imgprocessor.cpp \
    showwidget.cpp

HEADERS  += imgprocessor.h \
    showwidget.h

RESOURCES += \
    picture/str.qrc
