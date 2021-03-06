#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T20:25:05
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = joddy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += svg

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    joddygraphicview.cpp \
    osmparser.cpp \
    joddycontroller.cpp \
    nodestorage.cpp \
    object.cpp \
    building.cpp \
    way.cpp \
    settings.cpp \
    colorsettingswindow.cpp \
    nature.cpp

HEADERS += \
        mainwindow.h \
    joddygraphicview.h \
    osmparser.h \
    joddycontroller.h \
    nodestorage.h \
    object.h \
    building.h \
    way.h \
    settings.h \
    colorsettingswindow.h \
    nature.h

FORMS += \
        mainwindow.ui \
    colorsettingswindow.ui

DISTFILES += \
    source/logo.svg \
    source/logo.svg \
    source/zoom-in-button.svg \
    source/zoom-out-button.svg \
    settings.json
