//
// Created by Varun Srinivasan on 10/02/2025.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include "Ball.h"
#include "constants.h"

class Game {
public:
    Ball& ball;
public:
    Game(Ball& ball) : ball(ball){}

    void handleBallWallCollision();

};

#endif //CMAKESFMLPROJECT_GAME_H
