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
    src/views/mainwindow.cpp \
    src/views/itemscontainer.cpp \
    src/views/moviewidget.cpp \
    src/views/bookwidget.cpp \
    src/views/clickablelabel.cpp

HEADERS += src/models/item.h \
    src/models/book.h \
    src/models/movie.h \
    src/models/library.h \
    src/visitors/visitor.h \
    src/visitors/widgetvisitor.h \
    src/views/mainwindow.h \
    src/views/itemscontainer.h \
    src/views/moviewidget.h \
    src/views/bookwidget.h \
    src/views/clickablelabel.h

RESOURCES += src/storage/items.json \
    resources.qrc