CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ..

TEMPLATE = app
SOURCES += catch.hpp \
    ../untitled8/Point.cpp \
    ../untitled8/Rectangle.cpp \
    RectangleTester.cpp
SOURCES += mainTester.cpp
SOURCES +=


CONFIG += c++11

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -Wno-error=unused-variable

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    ../untitled8/Point.h \
    ../untitled8/Rectangle.h