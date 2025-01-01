#include "InputHandler.hpp"

void InputHandler::detectAttack(const std::optional<sf::Event> &event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Space key pressed (ATTACK)" << std::endl;
        }
    }
}

void InputHandler::detectMouseClick(const std::optional<sf::Event> &event)
{
    if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            std::cout << "Left mouse button pressed" << std::endl;
            std::cout << "Mouse coordinates: " << mouseButtonPressed->position.x << ", "
                      << mouseButtonPressed->position.y << std::endl;
        }
        else if (mouseButtonPressed->button == sf::Mouse::Button::Right)
        {
            std::cout << "Right mouse button pressed" << std::endl;
            std::cout << "Mouse coordinates: " << mouseButtonPressed->position.x << ", "
                      << mouseButtonPressed->position.y << std::endl;
        }
    }
}

void InputHandler::detectContinuousMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        std::cout << "Moving up" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        std::cout << "Moving down" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        std::cout << "Moving left" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        std::cout << "Moving right" << std::endl;
    }
}
