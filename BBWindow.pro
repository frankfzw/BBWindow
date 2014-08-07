#-------------------------------------------------
#
# Project created by QtCreator 2014-08-03T22:31:33
#
#-------------------------------------------------
# THE INCLUDEPATH AND LIBS SHOULD BE CHANGED BEFORE BUILDED

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BBWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socket.cpp

HEADERS  += mainwindow.h \
    socket.h

FORMS    += mainwindow.ui

LIBS        += -lvlc-qt -lvlc-qt-widgets

LIBS     += -L/home/frank/bb/vlc-qt/lib -lvlc-qt -lvlc-qt-widgets
INCLUDEPATH += /home/frank/bb/vlc-qt/include

CONFIG += release
