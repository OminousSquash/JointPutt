#include <SFML/Graphics.hpp>
#include "headers/View.h"
#include "headers/Actions.h"
#include "headers/Game.h"
#include "headers/Ball.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT}), "CMake SFML Project");
    window.setFramerateLimit(144);
    Ball b1(200, 500);
    Ball b2(700, 500);
    Hole h1(200, 100);
    Hole h2(700, 100);
    Game g(b1, b2, h1, h2);
    View v(window, g);
    Actions a;
    while (window.isOpen())
    {
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            a.DragBall(event, g.b1, g.b2, worldPos);
            a.ReleaseBall(event, g.b1, g.b2, worldPos);
        }
        g.handleBallsWallCollision();
        g.handleBallsHoleCollision();
        v.updateScreen();
    }
}
