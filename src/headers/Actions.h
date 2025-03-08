//
// Created by Varun Srinivasan on 10/02/2025.
//

#ifndef CMAKESFMLPROJECT_ACTIONS_H
#define CMAKESFMLPROJECT_ACTIONS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "constants.h"

class Actions {
public:
    bool ball1Held= false;
    bool ball2Held = false;
public:
    void DragBall(const std::optional<sf::Event>& event, Ball& b1, Ball& b2, sf::Vector2f& mousePos);

    void ReleaseBall(const std::optional<sf::Event>& event, Ball& b1, Ball& b2, sf::Vector2f& mousePos);
};

#endif //CMAKESFMLPROJECT_ACTIONS_H
