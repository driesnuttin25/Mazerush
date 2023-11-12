TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        main.cpp \
        maze.cpp \
        player.cpp \
        utils.cpp

HEADERS += \
    game.h \
    maze.h \
    player.h \
    utils.h
