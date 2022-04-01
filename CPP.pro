TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    TestFramework/testexception.cpp \
    TestFramework/timer.cpp \
    TestFramework/comparator.cpp \
    TestFramework/tostring.cpp \
    TestFramework/testlist.cpp \
    Problems/exampleproblem.cpp \
    Algorithms/generate.cpp \
    Algorithms/search.cpp \
    Algorithms/sort.cpp

HEADERS += \
    main.h \
    TestFramework/testexception.h \
    TestFramework/problem.h \
    TestFramework/timer.h \
    TestFramework/comparator.h \
    TestFramework/tostring.h \
    TestFramework/testlist.h \
    Problems/exampleproblem.h \
    problems.h \
    Algorithms/generate.h \
    Algorithms/search.h \
    Algorithms/sort.h
