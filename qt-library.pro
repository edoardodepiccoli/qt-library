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
    src/views/components/sidebar.cpp \
    src/views/searchview.cpp \
    src/views/formview.cpp \
    src/views/components/searchsection.cpp

HEADERS += src/models/item.h \
    src/models/book.h \
    src/models/movie.h \
    src/models/library.h \ \
    src/visitors/visitor.cpp \
    src/visitors/widgetvisitor.cpp \
    src/views/mainwindow.h \
    src/views/components/sidebar.h \
    src/views/searchview.h \
    src/views/formview.h \
    src/views/components/searchsection.h

RESOURCES += src/storage/items.json \
    src/views/assets/icons.qrc