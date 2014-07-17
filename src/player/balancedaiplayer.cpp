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

#include "balancedaiplayer.h"

BalancedAIPlayer::BalancedAIPlayer(QObject *parent) :
    Player(parent),
    _greed(parent),
    _tree(parent)
{
    QObject::connect(&_greed, SIGNAL(turn(int,int)), this, SLOT(getTurn(int,int)));
    QObject::connect(&_tree, SIGNAL(turn(int,int)), this, SLOT(getTurn(int,int)));
}

void BalancedAIPlayer::doTurn()
{
    emit wantBoard();
}

bool BalancedAIPlayer::isHuman()
{
    return false;
}

void BalancedAIPlayer::getBoard(Gameboard board, int player)
{
    int modifierPlaystile = _boarderLowHigh >= (board.points(player)+board.points(player==1?2:1))?_modifierPlaystileLow:_modifierPlaystileHigh;
    if(board.points(player) >= board.points(player==1?2:1)+modifierPlaystile)
    {
        emit sendMessage(tr("Now is the time to get all discs!"));
        _greed.getBoard(board, player);
    }
    else
    {
        emit sendMessage(tr("Maybe I should be a bit defensive"));
        _tree.getBoard(board, player);
    }
}

void BalancedAIPlayer::humanInput(int x, int y)
{
}

void BalancedAIPlayer::getTurn(int x, int y)
{
    emit turn(x, y);
}