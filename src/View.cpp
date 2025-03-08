//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/View.h"
#include "headers/constants.h"
#include <iostream>

void View::drawBall(Ball& b) {
    if (b.deactivated) {
        sf::CircleShape circle(CONSTANTS::BALL_RADIUS);
        circle.setPosition(sf::Vector2f (b.x, b.y));
        circle.setFillColor(sf::Color::Green);
        window.draw(circle);
        return;
    }
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
    circle.setFillColor(sf::Color::Blue);
    window.draw(circle);
}

void View::drawBarrier() {
    float x = CONSTANTS::BARRIER_X;
    float y = CONSTANTS::BARRIER_Y;
    sf::RectangleShape barrier(sf::Vector2f (CONSTANTS::BARRIER_WIDTH, CONSTANTS::BARRIER_HEIGHT));
    barrier.setPosition(sf::Vector2f (x, y));
    barrier.setFillColor(sf::Color::Blue);
    window.draw(barrier);
}

void View::drawBalls() {
    drawBall(game.b1);
    drawBall(game.b2);
}

void View::drawHoles() {
    Hole& h1 = game.h1;
    Hole& h2 = game.h2;
    sf::CircleShape hole1(CONSTANTS::HOLE_RADIUS);
    sf::CircleShape hole2(CONSTANTS::HOLE_RADIUS);
    hole1.setPosition(sf::Vector2f(h1.x, h1.y));
    hole2.setPosition(sf::Vector2f(h2.x, h2.y));
    hole1.setFillColor(sf::Color::White);
    hole2.setFillColor(sf::Color::White);
    window.draw(hole1);
    window.draw(hole2);
}

void View::updateScreen() {
    window.clear(sf::Color::Black);
    View::drawHoles();
    View::drawBalls();
    View::drawBarrier();
    window.display();
}
