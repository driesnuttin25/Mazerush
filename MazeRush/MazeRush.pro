QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Chest.cpp \
    Hole.cpp \
    Player.cpp \
    TitleScreen.cpp \
    main.cpp \
    maze.cpp \
    mazeview.cpp

HEADERS += \
    Chest.h \
    GameItem.h \
    Hole.h \
    Player.h \
    TitleScreen.h \
    maze.h \
    mazeview.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    game_resources.qrc
