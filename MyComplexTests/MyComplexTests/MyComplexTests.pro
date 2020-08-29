CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += .. \
    ../Assignment5/

TEMPLATE = app
SOURCES += catch.hpp \
    ../Assignment5/MyComplex.cpp \
    MyComplexTester.cpp \
    ../../Assignment5/MyComplex.cpp
SOURCES += mainTester.cpp
SOURCES +=


QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

# QMAKE_CXXFLAGS += -Werror
# QMAKE_CXXFLAGS += -Wno-error=unused-variable

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    ../Assignment5/MyComplex.h \
    ../../Assignment5/MyComplex.h
