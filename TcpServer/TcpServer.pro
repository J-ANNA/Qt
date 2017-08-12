#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T15:19:54
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp \
    tcpclientsocket.cpp \
    server.cpp

HEADERS  += tcpserver.h \
    tcpclientsocket.h \
    server.h
