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
    bool ballHeld = false;
public:
    void DragBall(const std::optional<sf::Event>& event, Ball& ball, sf::Vector2f& mousePos);

    void ReleaseBall(const std::optional<sf::Event>& event, Ball& ball, sf::Vector2f& mousePos);
};

#endif //CMAKESFMLPROJECT_ACTIONS_H
