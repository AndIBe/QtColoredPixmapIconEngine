TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    ColoredPixmapIconEngine \
    ExampleApp

ExampleApp.depends = ColoredPixmapIconEngine
