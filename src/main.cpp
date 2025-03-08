#include <SFML/Graphics.hpp>
#include "headers/View.h"
#include "headers/Actions.h"
#include "headers/Game.h"
#include "headers/Ball.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({CONSTANTS::WINDOW_WIDTH, CONSTANTS::WINDOW_HEIGHT}), "CMake SFML Project");
    window.setFramerateLimit(144);
    Ball b;
    Game g(b);
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
            a.DragBall(event, g.ball, worldPos);
            a.ReleaseBall(event, g.ball, worldPos);
        }
        g.handleBallWallCollision();
        v.updateScreen();
    }
}
