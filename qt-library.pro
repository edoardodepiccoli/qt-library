QT += core widgets
CONFIG += c++17
SOURCES += main.cpp 

SOURCES += $$files(src/**/*.cpp)
HEADERS += $$files(src/**/*.h)