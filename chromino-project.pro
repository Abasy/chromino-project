#-------------------------------------------------
#
# Project created by QtCreator 2017-11-27T11:46:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chromino-project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    sac.cpp \
    plateau.cpp \
    jeu.cpp \
    joueur.cpp \
    case.cpp \
    chromino.cpp \
    chrominotricolore.cpp \
    chrominobicolore.cpp \
    chrominounicolore.cpp \
    main.cpp \
    home.cpp \
    game.cpp

HEADERS += \
    sac.h \
    plateau.h \
    jeu.h \
    joueur.h \
    case.h \
    chromino.h \
    chrominotricolore.h \
    chrominobicolore.h \
    chrominounicolore.h \
    home.h \
    game.h

FORMS += \
    home.ui \
    config_joueurs.ui \
    game.ui \
    game.ui

RESOURCES += \
    ressources.qrc
