//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/Game.h"
#include <iostream>

void Game::handleBallWallCollision(Ball& ball, float maxLeft, float maxRight) {
    float leftX  = ball.x;
    float rightX = ball.x + 2 * CONSTANTS::BALL_RADIUS;
    float topY = ball.y;
    float bottomY = topY + 2 * CONSTANTS::BALL_RADIUS;

    // check left/right wall collision

    if (leftX <= maxLeft || rightX >= maxRight) {
        ball.xVel = -1 * ball.xVel;
    }

    if (topY <= CONSTANTS::BORDER_WIDTH || bottomY >= CONSTANTS::WINDOW_HEIGHT - CONSTANTS::BORDER_WIDTH) {
        ball.yVel = -1 * ball.yVel;
    }
    // check top/bottom wall collision
}

void Game::handleBallsWallCollision() {
    handleBallWallCollision(b1, CONSTANTS::BORDER_WIDTH, CONSTANTS::BARRIER_X - CONSTANTS::BORDER_WIDTH);
    handleBallWallCollision(b2, CONSTANTS::BARRIER_X + CONSTANTS::BORDER_WIDTH, CONSTANTS::WINDOW_WIDTH - CONSTANTS::BORDER_WIDTH);
}

void Game::deactivateBall(Ball &b, Hole& h) {
    b.deactivated = true;
    b.x = h.x;
    b.y = h.y;
}

void Game::handleBallsHoleCollision() {
    if (isBallHoleCollision(b1, h1)){
        deactivateBall(b1, h1);
    }
    if (isBallHoleCollision(b2, h2)) {
        deactivateBall(b2, h2);
    }
}

bool Game::isBallHoleCollision(Ball &b, Hole &h) {
    float cx1 = b.x + CONSTANTS::BALL_RADIUS;
    float cx2 = h.x + CONSTANTS::HOLE_RADIUS;
    float cy1 = b.y + CONSTANTS::BALL_RADIUS;
    float cy2 = h.y + CONSTANTS::HOLE_RADIUS;
    float distBetweenCentres  = (cx1 - cx2) * (cx1 - cx2) + (cy1 - cy2) * (cy1 - cy2);
    float maxDist = (CONSTANTS::BALL_RADIUS + CONSTANTS::HOLE_RADIUS) * (CONSTANTS::BALL_RADIUS + CONSTANTS::HOLE_RADIUS);
    return (distBetweenCentres <= maxDist);
}
