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

#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QAction>
#include "../core/gamemaster.h"

class Board : public QMainWindow
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

public slots:
    void openConfiguration();
    void exitGame();
    void boardChanged();
    void about();
    void rules();

private slots:
    void clicked(int x, int y);

    void lastChanged(int x, int y);
    void getMessage(QString s);
    void getHumanInput(int i);
    void finished(int player1, int player2);

private:
    Gamemaster gamemaster;
    QIcon black;
    QIcon white;
    QIcon empty;
    QIcon blackChanged;
    QIcon whiteChanged;
    QIcon emptyChanged;
    int lastX;
    int lastY;
    bool running;

    QVBoxLayout *mainLayout;
    QGridLayout *grid;
    QPushButton *buttons[8][8];
    QLabel *message;
    QLabel *playerMessage;
    QWidget *central;
    QAction *newGame;
    QAction *close;
    QAction *aboutQt;
    QAction *aboutReversi;
    QAction *showRules;
};

#endif // BOARD_H
