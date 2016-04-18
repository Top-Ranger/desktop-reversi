#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T13:09:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = desktop-reversi
TEMPLATE = app
CONFIG += c++11

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
    src/ui/gameconfiguration.cpp \
    src/ui/about.cpp \
    src/ui/rules.cpp \
    src/player/adaptivetreeaiplayer.cpp \
    src/ui/qreversibutton.cpp \
    src/player/controlaiplayer.cpp \
    src/player/assemblyaiplayer.cpp \
    src/player/AssemblyAIPlayer/movementcore.cpp \
    src/player/AssemblyAIPlayer/insanecore.cpp \
    src/player/AssemblyAIPlayer/greedycore.cpp \
    src/player/AssemblyAIPlayer/frontierdiscscore.cpp \
    src/player/AssemblyAIPlayer/freemovecore.cpp \
    src/player/AssemblyAIPlayer/edgecore.cpp \
    src/player/AssemblyAIPlayer/cornercore.cpp \
    src/player/AssemblyAIPlayer/core.cpp \
    src/player/AssemblyAIPlayer/centercore.cpp \
    src/player/AssemblyAIPlayer/assemblyaihelper.cpp \
    src/player/AssemblyAIPlayer/areacontrolcore.cpp \
    src/player/rules/rulehelper.cpp \
    src/player/rules/rule.cpp \
    src/player/rules/openingrule.cpp \
    src/player/rules/minimiseopponentmovementrule.cpp \
    src/player/rules/maximiseownmovementrule.cpp \
    src/player/rules/greedyrule.cpp \
    src/player/rules/fewerfrontierdiscsrule.cpp \
    src/player/rules/endgamerule.cpp \
    src/player/rules/cornerrule.cpp \
    src/player/neuralnetworkaiplayer.cpp \
    src/player/montecarloplayer.cpp

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
    src/ui/gameconfiguration.h \
    src/ui/about.h \
    version.h \
    src/ui/rules.h \
    src/player/adaptivetreeaiplayer.h \
    src/ui/qreversibutton.h \
    src/player/controlaiplayer.h \
    src/player/assemblyaiplayer.h \
    src/player/AssemblyAIPlayer/movementcore.h \
    src/player/AssemblyAIPlayer/insanecore.h \
    src/player/AssemblyAIPlayer/greedycore.h \
    src/player/AssemblyAIPlayer/frontierdiscscore.h \
    src/player/AssemblyAIPlayer/freemovecore.h \
    src/player/AssemblyAIPlayer/edgecore.h \
    src/player/AssemblyAIPlayer/cornercore.h \
    src/player/AssemblyAIPlayer/core.h \
    src/player/AssemblyAIPlayer/centercore.h \
    src/player/AssemblyAIPlayer/assemblyaihelper.h \
    src/player/AssemblyAIPlayer/areacontrolcore.h \
    src/player/rules/rulehelper.h \
    src/player/rules/rule.h \
    src/player/rules/openingrule.h \
    src/player/rules/minimiseopponentmovementrule.h \
    src/player/rules/maximiseownmovementrule.h \
    src/player/rules/greedyrule.h \
    src/player/rules/fewerfrontierdiscsrule.h \
    src/player/rules/endgamerule.h \
    src/player/rules/cornerrule.h \
    src/player/neuralnetworkaiplayer.h \
    src/core/commons.h \
    src/core/randomhelper.h \
    src/player/montecarloplayer.h

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
    README.md \
    src/player/NeuralNetworkAIPlayer/inputToHidden1.txt \
    src/player/NeuralNetworkAIPlayer/hidden2ToOutput.txt \
    src/player/NeuralNetworkAIPlayer/hidden1ToHidden2.txt

RESOURCES += \
    Resources.qrc \
    src/player/NeuralNetworkAIPlayer/NNData.qrc
    
RC_FILE = resources.rc
