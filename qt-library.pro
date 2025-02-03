QT += core gui widgets
CONFIG += c++11
CONFIG -= console app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/models/item.cpp \
    src/models/book.cpp \
    src/models/movie.cpp \
    src/models/library.cpp \
    src/views/mainwindow.cpp \
    src/views/components/sidebar.cpp \
    src/views/components/searchview.cpp \
    src/views/components/formview.cpp

HEADERS += src/models/item.h \
    src/models/book.h \
    src/models/movie.h \
    src/models/library.h \
    src/views/mainwindow.h \
    src/views/components/sidebar.h \
    src/views/components/searchview.h \
    src/views/components/formview.h

RESOURCES += src/storage/items.json \
    src/views/assets/icons.qrc