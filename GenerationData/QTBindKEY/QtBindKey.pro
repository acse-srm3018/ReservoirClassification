#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T22:50:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBindKey
TEMPLATE = app

CONFIG += c++11

LIBS+= "C:\Windows\System32\user32.dll"
#LIBS+= "C:\Windows\System32\"
#LIBS+= -L"C:\Windows\System32\" -luser32
LIBS+= -LC:\Windows\System32\
win32: LIBS += -luser32

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    keyboard.h

FORMS    += mainwindow.ui

