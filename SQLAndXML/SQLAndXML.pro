#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T14:28:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQLAndXML
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectdlg.cpp \
    editdialog.cpp

HEADERS  += mainwindow.h \
    connectdlg.h \
    editdialog.h

FORMS += \
    connectdlg.ui

DISTFILES +=

RESOURCES += \
    str.qrc
