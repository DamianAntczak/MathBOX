#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T12:38:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathBox
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wyrazenie.cpp \
    muParser/muParser.cpp \
    muParser/muParserBase.cpp \
    muParser/muParserBytecode.cpp \
    muParser/muParserCallback.cpp \
    muParser/muParserComplex.cpp \
    muParser/muParserDLL.cpp \
    muParser/muParserError.cpp \
    muParser/muParserInt.cpp \
    muParser/muParserTest.cpp \
    muParser/muParserTokenReader.cpp \
    draw.cpp \
    pochodna.cpp \
    matrix.cpp

HEADERS  += mainwindow.h \
    wyrazenie.h \
    muParser/muParser.h \
    muParser/muParserBase.h \
    muParser/muParserBytecode.h \
    muParser/muParserCallback.h \
    muParser/muParserComplex.h \
    muParser/muParserDef.h \
    muParser/muParserDLL.h \
    muParser/muParserError.h \
    muParser/muParserFixes.h \
    muParser/muParserInt.h \
    muParser/muParserStack.h \
    muParser/muParserTest.h \
    muParser/muParserToken.h \
    muParser/muParserTokenReader.h \
    draw.h \
    pochodna.h \
    matrix.h

FORMS    += mainwindow.ui
