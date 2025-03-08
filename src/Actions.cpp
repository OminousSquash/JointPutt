//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/Actions.h"

void Actions::DragBall(const std::optional<sf::Event> &event, Ball &ball, sf::Vector2f& mousePos) {
    if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed -> button == sf::Mouse::Button::Left) {
            int circleX= ball.x + CONSTANTS::BALL_RADIUS;
            int circleY= ball.y + CONSTANTS::BALL_RADIUS;
            int mouseX = mouseButtonPressed ->position.x;
            int mouseY = mouseButtonPressed -> position.y;
            if ((circleX - mouseX) * (circleX - mouseX) +
                (circleY - mouseY) * (circleY - mouseY) <= CONSTANTS::BALL_RADIUS * CONSTANTS::BALL_RADIUS) {
//                std::cout << "MOUSE PRESSED" << std::endl;
                this->ballHeld = true;
                return;
            }
        }
    }
}

void Actions::ReleaseBall(const std::optional<sf::Event> &event, Ball &ball, sf::Vector2f& mousePos) {
    if (const auto* mouseButtonRelease= event->getIf<sf::Event::MouseButtonReleased>()) {
//        std::cout << "MOUSE RELEASED" << std::endl;
        if (this->ballHeld)  {
            this->ballHeld = false;
            int mouseX = mouseButtonRelease -> position.x;
            int mouseY = mouseButtonRelease -> position.y;
            ball.xVel = ball.x - mouseX;
            std::cout << "xVel(pre update): " << ball.xVel << std::endl;
            ball.xVel = ball.xVel > CONSTANTS::MAX_X_VELOCITY ? CONSTANTS::MAX_X_VELOCITY : ball.xVel;
            ball.xVel = ball.xVel < CONSTANTS::MIN_X_VELOCITY ? CONSTANTS::MIN_X_VELOCITY: ball.xVel;

            ball.yVel = ball.y - mouseY;
            std::cout << "yVel(pre update): " << ball.yVel << std::endl;
            ball.yVel = ball.yVel > CONSTANTS::MAX_Y_VELOCITY ? CONSTANTS::MAX_Y_VELOCITY : ball.yVel;
            ball.yVel = ball.yVel < CONSTANTS::MIN_Y_VELOCITY ? CONSTANTS::MIN_Y_VELOCITY : ball.yVel;

        }
    }
}
