/*
  Copyright (C) 2014 Marcus Soll
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "board.h"
#include "gameconfiguration.h"
#include <QMessageBox>
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include "about.h"
#include "rules.h"
#include "qreversibutton.h"

Board::Board(QWidget *parent)
    : QMainWindow(parent),
      gamemaster(),
      black(":discs/src/ui/1.png"),
      white(":discs/src/ui/2.png"),
      empty(":discs/src/ui/0.png"),
      blackChanged(":discs/src/ui/1changed.png"),
      whiteChanged(":discs/src/ui/2changed.png"),
      emptyChanged(":discs/src/ui/0changed.png"),
      lastX(-1),
      lastY(-1),
      running(true)
{
    setWindowIcon(QIcon(":icon/desktop-reversi.png"));
    setWindowTitle("desktop-reversi");

    // Create the board
    // Grid
    grid = new QGridLayout();

    for(int x = 0; x < 8; ++x)
    {
        for(int y = 0; y < 8; ++y)
        {
            buttons[x][y] = new QReversiButton(x,y,this);
            buttons[x][y]->setFlat(true);
            buttons[x][y]->setIcon(empty);
            buttons[x][y]->setIconSize(QSize(50,50));
            QObject::connect(buttons[x][y],SIGNAL(clicked(int,int)),this,SLOT(clicked(int,int)));
            grid->addWidget(buttons[x][y],x,y);
        }
    }

    mainLayout = new QVBoxLayout();
    playerMessage = new QLabel("Waiting...");
    mainLayout->addWidget(playerMessage);
    mainLayout->addLayout(grid);

    central = new QWidget();
    central->setLayout(mainLayout);
    this->setCentralWidget(central);

    QObject::connect(&gamemaster, SIGNAL(boardChanged()),this,SLOT(boardChanged()));
    QObject::connect(&gamemaster, SIGNAL(lastDiscPlayed(int,int)),this,SLOT(lastChanged(int,int)));
    QObject::connect(&gamemaster, SIGNAL(sendMessage(QString)),this,SLOT(getMessage(QString)));
    QObject::connect(&gamemaster, SIGNAL(getHumanInput(int)),this,SLOT(getHumanInput(int)));
    QObject::connect(&gamemaster, SIGNAL(result(int,int)),this,SLOT(finished(int,int)));

    close = new QAction("Exit",this);
    newGame = new QAction("Start new game", this);
    newGame->setShortcut(QKeySequence::New);
    aboutQt = new QAction("About Qt", this );
    aboutReversi = new QAction("About",this);
    showRules = new QAction("Rules", this);

    QObject::connect(aboutQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    QObject::connect(close,SIGNAL(triggered()),this,SLOT(exitGame()));
    QObject::connect(newGame,SIGNAL(triggered()),this,SLOT(openConfiguration()));
    QObject::connect(aboutReversi,SIGNAL(triggered()),this,SLOT(about()));
    QObject::connect(showRules,SIGNAL(triggered()),this,SLOT(rules()));

    QMenuBar *menubar = menuBar();

    QMenu *file = menubar->addMenu("File");
    file->addAction(newGame);
    file->addAction(showRules);
    file->addSeparator();
    file->addAction(close);
    QMenu *about = menubar->addMenu("About");
    about->addAction(aboutReversi);
    about->addAction(aboutQt);

    setFixedSize(minimumSize());

    gamemaster.initialise("Human","Human",0);
    gamemaster.startGame();
    boardChanged();
}

Board::~Board()
{
    delete grid;
    for(int x = 0; x < 8; ++x)
    {
        for(int y = 0; y < 8; ++y)
        {
            delete buttons[x][y];
        }
    }
    delete central;
    delete close;
    delete newGame;
    delete aboutQt;
    delete aboutReversi;
    delete showRules;
}

void Board::openConfiguration()
{
    GameConfiguration config;
    if(config.exec() == config.Accepted)
    {
        lastX = -1;
        lastY = -1;
        gamemaster.initialise(config.player1(), config.player2(), config.bonus());
        running = true;
        boardChanged();
        gamemaster.startGame();
    }
}

void Board::exitGame()
{
    if( QMessageBox::warning(this,
                             "Close",
                             "Really Quit?",
                             QMessageBox::Yes|QMessageBox::No,
                             QMessageBox::No) == QMessageBox::Yes)
    {
        exit(EXIT_SUCCESS);
    }
}

void Board::about()
{
    About *window = new About(this);
    window->exec();
    delete window;
}

void Board::rules()
{
    Rules *window = new Rules(this);
    window->exec();
    delete window;
}

void Board::boardChanged()
{
    for(int x = 0; x < 8; ++x)
    {
        for(int y = 0; y < 8; ++y)
        {
            if((x == lastX) && (y == lastY))
            {
                if(gamemaster.getOwner(x,y) == 1)
                {
                    buttons[x][y]->setIcon(blackChanged);
                }
                else if(gamemaster.getOwner(x,y) == 2)
                {
                    buttons[x][y]->setIcon(whiteChanged);
                }
                else
                {
                    buttons[x][y]->setIcon(emptyChanged);
                }
            }
            else
            {
                if(gamemaster.getOwner(x,y) == 1)
                {
                    buttons[x][y]->setIcon(black);
                }
                else if(gamemaster.getOwner(x,y) == 2)
                {
                    buttons[x][y]->setIcon(white);
                }
                else
                {
                    buttons[x][y]->setIcon(empty);
                }
            }
        }
    }
    repaint();
}

void Board::clicked(int x, int y)
{
    if(running)
    {
        playerMessage->setText("Waiting...");
    }
    gamemaster.getInput(x,y);
}

void Board::lastChanged(int x, int y)
{
    if((lastX != -1) && (lastY != -1))
    {
        if(gamemaster.getOwner(lastX,lastY) == 1)
        {
            buttons[lastX][lastY]->setIcon(black);
        }
        else if(gamemaster.getOwner(lastX,lastY) == 2)
        {
            buttons[lastX][lastY]->setIcon(white);
        }
        else
        {
            buttons[lastX][lastY]->setIcon(empty);
        }
    }

    lastX = x;
    lastY = y;

    if(gamemaster.getOwner(lastX,lastY) == 1)
    {
        buttons[lastX][lastY]->setIcon(blackChanged);
    }
    else if(gamemaster.getOwner(lastX,lastY) == 2)
    {
        buttons[lastX][lastY]->setIcon(whiteChanged);
    }
    else
    {
        buttons[lastX][lastY]->setIcon(emptyChanged);
    }
}

void Board::getMessage(QString s)
{
    QMessageBox::information(this,
                             QString("Message"),
                             s);
}

void Board::getHumanInput(int i)
{
    if(running)
    {
        playerMessage->setText(QString("Player %1 do your turn").arg(i));
    }
}

void Board::finished(int player1, int player2)
{
    running = false;
    playerMessage->setText("Finished!");
    QMessageBox::information(this,
                             QString("Result"),
                             QString("Finished!\nPlayer 1: %1\nPlayer 2: %2").arg(player1).arg(player2));
}
