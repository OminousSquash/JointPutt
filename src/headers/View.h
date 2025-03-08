//
// Created by Varun Srinivasan on 10/02/2025.
//

#ifndef CMAKESFMLPROJECT_VIEW_H
#define CMAKESFMLPROJECT_VIEW_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class View {
public:
    sf::RenderWindow& window;
    Game& game;
public:
    View(sf::RenderWindow& window, Game& game) : window(window), game(game){}

    void updateScreen();
    void drawBall(Ball& ball);
    void drawBalls();
};

#endif //CMAKESFMLPROJECT_VIEW_H
