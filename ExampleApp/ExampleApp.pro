#-------------------------------------------------
#
# Project created by QtCreator 2018-03-30T23:39:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExampleApp
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

QTPLUGIN += ColoredPixmapIconEngine

SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui


# rebuild app when library was changed
depend_on_file.target = depend_on_file
depend_on_file.depends = $$OUT_PWD/../ColoredPixmapIconEngine/plugins/iconengines/libColoredPixmapIconEngine.a
depend_on_file.CONFIG += recursive
QMAKE_EXTRA_TARGETS += depend_on_file
PRE_TARGETDEPS += depend_on_file


LIBS += -L../ColoredPixmapIconEngine/plugins/iconengines/ -lColoredPixmapIconEngine

RESOURCES += \
    resources.qrc
