QT += core gui widgets
CONFIG += c++11
CONFIG -= console app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/models/item.cpp \
    src/models/book.cpp \
    src/models/movie.cpp \
    src/models/library.cpp \
    src/visitors/visitor.cpp \
    src/visitors/widgetvisitor.cpp \

HEADERS += src/models/item.h \
    src/models/book.h \
    src/models/movie.h \
    src/models/library.h \ \
    src/visitors/visitor.cpp \
    src/visitors/widgetvisitor.cpp \

RESOURCES += items.json \
    src/views/assets/icons.qrc