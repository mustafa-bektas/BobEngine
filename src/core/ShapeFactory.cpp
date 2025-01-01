#include "ShapeFactory.hpp"

#include <iostream>

sf::RectangleShape createRectangle(const sf::Vector2f size, const sf::Vector2f position, const sf::Color color)
{
    sf::RectangleShape rectangle {};
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);

    return rectangle;
}

sf::CircleShape createCircle(const float radius, const sf::Vector2f position, const sf::Color color)
{
    sf::CircleShape circle {};
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(color);

    return circle;
}

sf::Text createText(const sf::Font& font, const sf::String& string, const int charSize, const sf::Color color, const sf::Vector2f position)
{
    sf::Text text(font);
    text.setString(string);
    text.setCharacterSize(charSize);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(position);

    return text;
}
