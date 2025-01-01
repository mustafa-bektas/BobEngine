#include "GameLoop.hpp"

GameLoop::GameLoop(sf::RenderWindow& window, InputHandler& inputHandler)
    : window(window), inputHandler(inputHandler) {}



void GameLoop::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void GameLoop::processEvents()
{
    inputHandler.detectContinuousMovement();

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        inputHandler.detectAttack(event);
        inputHandler.detectMouseClick(event);
    }
}

void GameLoop::update()
{
    // Future update logic
}

void GameLoop::render()
{
    window.clear(sf::Color::Black);

    window.display();
}
