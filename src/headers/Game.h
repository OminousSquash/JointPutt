//
// Created by Varun Srinivasan on 10/02/2025.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include "Ball.h"
#include "constants.h"
#include "Hole.h"

class Game {
public:
    Ball& b1;
    Ball& b2;
    Hole& h1;
    Hole& h2;

public:
    Game(Ball& b1, Ball& b2, Hole& h1, Hole& h2) : b1(b1), b2(b2), h1(h1), h2(h2) {}

    void handleBallWallCollision(Ball& ball, float maxLeft, float maxRight);
    void handleBallsWallCollision();

    void handleBallsHoleCollision();
    bool isBallHoleCollision(Ball& b, Hole& h);
    void deactivateBall(Ball& b, Hole& h);
};

#endif //CMAKESFMLPROJECT_GAME_H
