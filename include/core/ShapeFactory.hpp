#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <SFMl/Graphics.hpp>

sf::RectangleShape createRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color);
sf::CircleShape createCircle(float radius, sf::Vector2f position, sf::Color color);
sf::Text createText(const sf::Font& font, const sf::String& string, int charSize, sf::Color color, sf::Vector2f position);

#endif // SHAPEFACTORY_HPP
