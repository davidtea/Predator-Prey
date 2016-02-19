TEMPLATE = app
CONFIG += console
CONFIG -= qt
QT += widgets

SOURCES += main.cpp \
    grid.cpp \
    creature.cpp \
    hunter.cpp \
    prey.cpp \
    wall.cpp

HEADERS += \
    grid.h \
    creature.h \
    hunter.h \
    prey.h \
    wall.h

