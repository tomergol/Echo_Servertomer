QT += core
QT -= gui

CONFIG += c++11

TARGET = Echo_server-server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../socketClass.cpp \
    server.cpp \
    socketClass.cpp

HEADERS += \
    ../server.h \
    ../socketClass.h \
    server.h \
    socketClass.h
