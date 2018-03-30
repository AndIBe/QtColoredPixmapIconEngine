QT += core-private gui-private

#CONFIG += static

TARGET  = ColoredPixmapIconEngine

HEADERS += \
    ColoredPixmapIconEngine.h

SOURCES += \
    main.cpp \
    ColoredPixmapIconEngine.cpp

OTHER_FILES += \
    ColoredPixmapIconEngine.json \
    .qmake.conf

DISTFILES += \
    ColoredPixmapIconEngine.json


PLUGIN_TYPE = iconengines
PLUGIN_CLASS_NAME = ColoredIconEnginePlugin
PLUGIN_EXTENDS = -
load(qt_plugin)
