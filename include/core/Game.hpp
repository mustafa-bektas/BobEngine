#ifndef GAME_HPP
#define GAME_HPP

#include <SFMl/Graphics.hpp>
#include "GameLoop.hpp"

class Game
{
public:
    Game(int width, int height, const std::string& title);
    ~Game();

    void run();

private:
    sf::RenderWindow window;
    InputHandler inputHandler;
    GameLoop gameLoop;

    void init();
    void cleanup();
};

#endif // GAME_HPP
