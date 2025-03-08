//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/Game.h"

void Game::handleBallWallCollision(Ball& ball) {
    float leftX  = ball.x;
    float rightX = ball.x + 2 * CONSTANTS::BALL_RADIUS;
    float topY = ball.y;
    float bottomY = topY + 2 * CONSTANTS::BALL_RADIUS;

    // check left/right wall collision

    if (leftX <= CONSTANTS::BORDER_WIDTH || rightX >= CONSTANTS::WINDOW_WIDTH - CONSTANTS::BORDER_WIDTH) {
        ball.xVel = -1 * ball.xVel;
    }

    if (topY <= CONSTANTS::BORDER_WIDTH || bottomY >= CONSTANTS::WINDOW_HEIGHT - CONSTANTS::BORDER_WIDTH) {
        ball.yVel = -1 * ball.yVel;
    }
    // check top/bottom wall collision
}

void Game::handleBallsWallCollision() {
    handleBallWallCollision(b1);
    handleBallWallCollision(b2);
}
