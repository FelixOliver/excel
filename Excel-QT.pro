#-------------------------------------------------
#
# Project created by QtCreator 2013-06-16T10:08:27
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Excel-QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    nodecell.cpp \
    nodeconst.cpp \
    nodeoperator.cpp \
    syntaxanalizer.cpp \
    operations.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    node.h \
    nodecell.h \
    nodeconst.h \
    nodeoperator.h \
    syntaxanalizer.h \
    operations.h \
    cell.h \
    matrix.h

FORMS    += mainwindow.ui
