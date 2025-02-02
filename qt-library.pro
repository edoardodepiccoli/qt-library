QT += core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/models/item.cpp \
    src/models/book.cpp \
    src/models/movie.cpp \
    src/models/library.cpp

HEADERS += src/models/item.h \
    src/models/book.h \
    src/models/movie.h \
    src/models/library.h