//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/View.h"
#include "headers/constants.h"
#include <iostream>

void View::drawBall(Ball& b) {
    b.xVel = CONSTANTS::FRICTION * b.xVel;
    b.yVel = CONSTANTS::FRICTION * b.yVel;
    if (abs(b.xVel) < 0.01) {
        b.xVel = 0;
    }
    if (abs(b.xVel) < 0.01) {
        b.yVel = 0;
    }
    b.x += b.xVel;
    b.y += b.yVel;
    sf::CircleShape circle(CONSTANTS::BALL_RADIUS);
    circle.setPosition(sf::Vector2f (b.x, b.y));
    circle.setFillColor(sf::Color::Green);
    window.draw(circle);
}

void View::drawBalls() {
    drawBall(game.b1);
    drawBall(game.b2);
}

void View::updateScreen() {
    window.clear(sf::Color::Black);
    View::drawBalls();
    window.display();
}
