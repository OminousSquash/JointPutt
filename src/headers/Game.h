//
// Created by Varun Srinivasan on 10/02/2025.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include "Ball.h"
#include "constants.h"

class Game {
public:
    Ball& b1;
    Ball& b2;

public:
    Game(Ball& b1, Ball& b2) : b1(b1), b2(b2){}

    void handleBallWallCollision(Ball& ball);
    void handleBallsWallCollision();

};

#endif //CMAKESFMLPROJECT_GAME_H
