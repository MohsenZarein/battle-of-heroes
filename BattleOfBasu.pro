TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    menu.cpp \
    game.cpp \
    grid.cpp \
    player.cpp \
    mrsghost.cpp \
    hero.cpp \
    card.cpp \
    mrsghostcard.cpp \
    robicard.cpp \
    leoncard.cpp \
    robi.cpp \
    drmarrycard.cpp \
    snippercard.cpp \
    kratoscard.cpp \
    giantcard.cpp \
    alphamancard.cpp \
    professorcard.cpp \
    commandercard.cpp \
    leon.cpp \
    drmarry.cpp \
    snipper.cpp \
    kratos.cpp \
    giant.cpp \
    alphaman.cpp \
    professor.cpp \
    commander.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/release/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/debug/ -lsfml-window
else:unix: LIBS += -L$$PWD/../../SFML-2.5.1/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../SFML-2.5.1/include
DEPENDPATH += $$PWD/../../SFML-2.5.1/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/release/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/debug/ -lsfml-system
else:unix: LIBS += -L$$PWD/../../SFML-2.5.1/lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../SFML-2.5.1/include
DEPENDPATH += $$PWD/../../SFML-2.5.1/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SFML-2.5.1/lib/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/../../SFML-2.5.1/lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../SFML-2.5.1/include
DEPENDPATH += $$PWD/../../SFML-2.5.1/include

HEADERS += \
    menu.h \
    game.h \
    grid.h \
    player.h \
    mrsghost.h \
    hero.h \
    card.h \
    mrsghostcard.h \
    robicard.h \
    leoncard.h \
    general.h \
    robi.h \
    drmarrycard.h \
    snippercard.h \
    kratoscard.h \
    giantcard.h \
    alphamancard.h \
    professorcard.h \
    commandercard.h \
    leon.h \
    drmarry.h \
    snipper.h \
    kratos.h \
    giant.h \
    alphaman.h \
    professor.h \
    commander.h
