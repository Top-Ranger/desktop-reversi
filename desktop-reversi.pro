#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T13:09:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = desktop-reversi
TEMPLATE = app

release {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

SOURCES += src/main.cpp\
        src/ui/board.cpp \
    src/core/gamemaster.cpp \
    src/core/gameboard.cpp \
    src/player/tutorialplayer.cpp \
    src/player/treeaiplayer.cpp \
    src/player/staticruleaiplayer.cpp \
    src/player/randomaiplayer.cpp \
    src/player/player.cpp \
    src/player/humanplayer.cpp \
    src/player/greedyaiplayer.cpp \
    src/player/balancedaiplayer.cpp \
    src/rules/rule.cpp \
    src/rules/openingrule.cpp \
    src/rules/minimiseopponentmovementrule.cpp \
    src/rules/maximiseownmovementrule.cpp \
    src/rules/greedyrule.cpp \
    src/rules/fewerfrontierdiscsrule.cpp \
    src/rules/endgamerule.cpp \
    src/rules/cornerrule.cpp \
    src/ui/gameconfiguration.cpp \
    src/ui/about.cpp \
    src/ui/rules.cpp \
    src/player/adaptivetreeaiplayer.cpp \
    src/ui/qreversibutton.cpp \
    src/player/controlaiplayer.cpp

HEADERS  += src/ui/board.h \
    src/core/gamemaster.h \
    src/core/gameboard.h \
    src/player/tutorialplayer.h \
    src/player/treeaiplayer.h \
    src/player/staticruleaiplayer.h \
    src/player/randomaiplayer.h \
    src/player/player.h \
    src/player/humanplayer.h \
    src/player/greedyaiplayer.h \
    src/player/balancedaiplayer.h \
    src/rules/rule.h \
    src/rules/openingrule.h \
    src/rules/minimiseopponentmovementrule.h \
    src/rules/maximiseownmovementrule.h \
    src/rules/greedyrule.h \
    src/rules/fewerfrontierdiscsrule.h \
    src/rules/endgamerule.h \
    src/rules/cornerrule.h \
    src/ui/gameconfiguration.h \
    src/ui/about.h \
    version.h \
    src/ui/rules.h \
    src/player/adaptivetreeaiplayer.h \
    src/ui/qreversibutton.h \
    src/player/controlaiplayer.h

FORMS += \
    src/ui/gameconfiguration.ui \
    src/ui/about.ui \
    src/ui/rules.ui

OTHER_FILES += \
    src/ui/2changed.png \
    src/ui/2.png \
    src/ui/1changed.png \
    src/ui/1.png \
    src/ui/0changed.png \
    src/ui/0.png \
    templates/desktop-reversi.svg \
    templates/2changed.svg \
    templates/2.svg \
    templates/1changed.svg \
    templates/1.svg \
    templates/0changed.svg \
    templates/0.svg \
    desktop-reversi.png \
    desktop-reversi.ico \
    .gitignore \
    resources.rc \
    LICENSE.txt \
    README.md

RESOURCES += \
    Resources.qrc
    
RC_FILE = resources.rc
