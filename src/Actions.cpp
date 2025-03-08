//
// Created by Varun Srinivasan on 10/02/2025.
//

#include "headers/Actions.h"

bool cirlceIntersect(float cx, float cy, float mx, float my) {
    if ((mx - cx) * (mx - cx) + (my - cy) * (my - cy)
        <= CONSTANTS::BALL_RADIUS * CONSTANTS::BALL_RADIUS) {
        return true;
    }
    return false;
}

void Actions::DragBall(const std::optional<sf::Event> &event, Ball &b1, Ball& b2, sf::Vector2f& mousePos) {
    if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed -> button == sf::Mouse::Button::Left) {
            float cx1 = b1.x + CONSTANTS::BALL_RADIUS;
            float cy1 = b1.y + CONSTANTS::BALL_RADIUS;

            float cx2 = b2.x + CONSTANTS::BALL_RADIUS;
            float cy2 = b2.y + CONSTANTS::BALL_RADIUS;

            float mx = 1.0 * mouseButtonPressed->position.x;
            float my = 1.0 * mouseButtonPressed -> position.y;
            if (cirlceIntersect(cx1, cy1, mx, my)) {
                this->ball1Held= true;
                return;
            }
            if (cirlceIntersect(cx2, cy2, mx, my)) {
                this -> ball2Held = true;
                return;
            }
        }
    }
}

void setVelocities(Ball& ball, float xVel, float yVel) {
    ball.xVel = xVel;
    ball.yVel = yVel;
}

void Actions::OnRelease(Ball& b1, Ball& b2, float mouseX, float mouseY) {
    float cx = b1.x + CONSTANTS::BALL_RADIUS;
    float cy = b1.y + CONSTANTS::BALL_RADIUS;
    b1.xVel = cx - mouseX;
    std::cout << "xVel(without correction): " << b1.xVel << std::endl;
    b1.xVel = b1.xVel > CONSTANTS::MAX_X_VELOCITY ? CONSTANTS::MAX_X_VELOCITY : b1.xVel;
    b1.xVel = b1.xVel < CONSTANTS::MIN_X_VELOCITY ? CONSTANTS::MIN_X_VELOCITY: b1.xVel;


    b1.yVel = cy - mouseY;
    std::cout << "yVel(without correction): " << b1.yVel << std::endl;
    b1.yVel = b1.yVel > CONSTANTS::MAX_Y_VELOCITY ? CONSTANTS::MAX_Y_VELOCITY : b1.yVel;
    b1.yVel = b1.yVel < CONSTANTS::MIN_Y_VELOCITY ? CONSTANTS::MIN_Y_VELOCITY : b1.yVel;
    setVelocities(b2, b1.xVel, b1.yVel);
}

void Actions::ReleaseBall(const std::optional<sf::Event> &event, Ball &b1, Ball& b2, sf::Vector2f& mousePos) {
    if (const auto* mouseButtonRelease= event->getIf<sf::Event::MouseButtonReleased>()) {
        if (this->ball1Held)  {
            this->ball1Held= false;
            float mouseX = mouseButtonRelease ->position.x;
            float mouseY = mouseButtonRelease ->position.y;
            Actions::OnRelease(b1, b2,mouseX, mouseY);
        } else if (this -> ball2Held) {
            this->ball2Held = false;
            int mouseX = mouseButtonRelease -> position.x;
            int mouseY = mouseButtonRelease -> position.y;
            Actions::OnRelease(b1, b2, mouseX, mouseY);
        }
    }
}
