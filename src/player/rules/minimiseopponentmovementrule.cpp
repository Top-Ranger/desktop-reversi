/*
  Copyright (C) 2014,2015,2016 Marcus Soll
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

#include "minimiseopponentmovementrule.h"

#include "rulehelper.h"
#include "../../core/randomhelper.h"
#include "../../core/commons.h"

using RuleHelper::canTakeCorner;
using RuleHelper::canGetZeroDiscs;
using RuleHelper::getPossibleTurn;
using RuleHelper::possibleMove;

using ReversiCommons::opponent;

const int MinimiseOpponentMovementRule::_borderMoves;

MinimiseOpponentMovementRule::MinimiseOpponentMovementRule(QObject *parent) :
    Rule(parent),
    _x(-1),
    _y(-1),
    _asked(false)
{
    RandomHelper::initialise();
}

bool MinimiseOpponentMovementRule::applicable(Gameboard board, int player)
{
    bool returnValue = calculateMove(board, player);
    deleteMove();
    return returnValue;
}

void MinimiseOpponentMovementRule::doTurn(Gameboard board, int player)
{
    calculateMove(board, player);
    if(_asked)
    {
        int x = _x;
        int y = _y;
        deleteMove();
        emit turn(x,y);
        return;
    }
    else
    {
        possibleMove move = getPossibleTurn(board, player);
        if(move.possible)
        {
            emit turn(move.x, move.y);
        }
        else
        {
            REVERSI_ERROR_MSG(": No possible move");
        }
    }
}

QString MinimiseOpponentMovementRule::name()
{
    return tr("Minimise Opponent Movement Rule");
}

bool MinimiseOpponentMovementRule::calculateMove(Gameboard board, int player)
{
    int min = 100;
    int x = RandomHelper::random_place();
    int y = RandomHelper::random_place();
    int xstart = x;
    int ystart = y;
    int xmin = -1;
    int ymin = -1;
    int opponentPlayer = opponent(player);
    Gameboard testboard;

    do
    {
        do
        {
            testboard = board;

            if(testboard.play(x,y,player))
            {
                int temp = 0;

                for(int opponentX = 0; opponentX < 8; ++opponentX)
                {
                    for(int opponentY = 0; opponentY < 8; ++opponentY)
                    {
                        if(testboard.play(opponentX, opponentY,opponentPlayer,true))
                        {
                            ++temp;
                        }
                    }
                }

                if(temp < min && (!canTakeCorner(testboard, opponent(player))) && (!canGetZeroDiscs(testboard,player)))
                {
                    min = temp;
                    xmin = x;
                    ymin = y;
                }
            }

            y = (y+1)%8;
        }while(y != ystart);

        x = (x+1)%8;
    }while(x != xstart);

    if(min <= _borderMoves)
    {
        _x = xmin;
        _y = ymin;
        _asked = true;
    }
    else
    {
        _x = -1;
        _y = -1;
        _asked = false;
    }
    return _asked;
}

void MinimiseOpponentMovementRule::deleteMove()
{
    _x = -1;
    _y = -1;
    _asked = false;
}
