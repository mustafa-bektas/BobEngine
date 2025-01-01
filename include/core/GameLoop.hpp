#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include <SFMl/Graphics.hpp>
#include "InputHandler.hpp"
#include "ShapeFactory.hpp"

class GameLoop
{
public:
    GameLoop(sf::RenderWindow& window, InputHandler& inputHandler);
    void run();

private:
    sf::RenderWindow& window;
    InputHandler inputHandler;

    void processEvents();
    void update();
    void render();
};

#endif // GAMELOOP_HPP
