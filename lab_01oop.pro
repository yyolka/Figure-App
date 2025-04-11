TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console

SOURCES += \
        circle.cpp \
        main.cpp \
        menu.cpp \
        point.cpp \
        rectangle.cpp \
        triangle.cpp

HEADERS += \
    circle.h \
    error.h \
    menu.h \
    point.h \
    rectangle.h \
    shape.h \
    triangle.h
