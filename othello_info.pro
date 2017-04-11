QT += core
QT -= gui

CONFIG += c++11

TARGET = othello_info
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pion.cpp \
    grille.cpp \
    manager.cpp \
    partie.cpp

HEADERS += \
    pion.h \
    grille.h \
    manager.h \
    partie.h
