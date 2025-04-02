TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console

SOURCES += \
        actions.cpp \
        circle.cpp \
        menu.cpp \
        output.cpp \
        point.cpp \
        rectangle.cpp \
        triangle.cpp

HEADERS += \
    actions.h \
    circle.h \
    error.h \
    menu.h \
    output.h \
    point.h \
    rectangle.h \
    shape.h \
    triangle.h
