#include "Game.hpp"
#include <iostream>

Game::Game(const int width, const int height, const std::string& title)
    : window(sf::VideoMode({static_cast<unsigned>(width), static_cast<unsigned>(height)}), title), gameLoop(window, inputHandler)
{
    init();
}

Game::~Game()
{
    cleanup();
}

void Game::init()
{
    std::cout << "Game Initialized!" << std::endl;
}

void Game::cleanup()
{
    std::cout << "Game Cleaned Up!" << std::endl;
}

void Game::run()
{
    gameLoop.run();
}
