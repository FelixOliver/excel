#-------------------------------------------------
#
# Project created by QtCreator 2013-07-29T11:11:17
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++11

QT       += core gui

qtHaveModule(printsupport): QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExcelCS-QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    Operations.cpp \
    SyntaxAnalizer.cpp \
    Cell.cpp \
    LexicalAnalizer.cpp \
    PreviewPrint.cpp \
    Save_Load.cpp


HEADERS  += mainwindow.h\
    Node.h \
    NodeConst.h \
    NodeOperator.h \
    NodeCell.h \
    Includes.h \
    Operations.h \
    SyntaxAnalizer.h \
    Cell.h \
    LexicalAnalizer.h \
    SparseMatrix.h \
    LexicalError.h \
    PreviewPrint.h \
    Save_Load.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
