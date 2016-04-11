#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T10:14:11
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGame
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Player.cpp \
    Score.cpp \
    Health.cpp \
    PowerUp.cpp \
    Spawn.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Player.h \
    Score.h \
    Health.h \
    PowerUp.h \
    Spawn.h

FORMS    +=

RESOURCES += \
    res.qrc
