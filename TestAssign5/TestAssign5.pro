CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += ..

TEMPLATE = app
SOURCES += catch.hpp \
    ../Assignment/Spring 2016/CS 162/Assignment5/MyComplex.cpp \
    ../Assignment/Spring 2016/CS 162/Assignment5/MyComplex.cpp \
    MyComplex.cpp
SOURCES += mainTester.cpp
SOURCES += sampleTester.cpp


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
    ../Assignment/Spring 2016/CS 162/Assignment5/MyComplex.h \
    ../Assignment/Spring 2016/CS 162/Assignment5/MyComplex.h \
    MyComplex.h