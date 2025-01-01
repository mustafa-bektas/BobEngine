#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SFMl/Graphics.hpp>
#include <iostream>
#include <optional>

class InputHandler
{
public:
    void detectAttack(const std::optional<sf::Event> &event);
    void detectMouseClick(const std::optional<sf::Event> &event);
    void detectContinuousMovement();
};

#endif // INPUTHANDLER_HPP
