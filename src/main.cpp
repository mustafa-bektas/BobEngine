#include <iostream>
#include <SFMl/Graphics.hpp>

sf::RectangleShape createRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color);
sf::CircleShape createCircle(float radius, sf::Vector2f position, sf::Color color);
sf::Text createText(const sf::Font& font, const sf::String& string, int charSize, sf::Color color, sf::Vector2f position);
void detectAttack(const std::optional<sf::Event> &event);
void detectMouseClick(const std::optional<sf::Event> &event);
void detectContinuousMovement();

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800,600}), "My Window");

    const sf::Font font("../../assets/arial.ttf");

    const auto rectangle = createRectangle({250, 250}, {35, 100}, sf::Color::Red);
    const auto circle = createCircle(75, {500, 400}, sf::Color::Blue);
    const auto text = createText(font, "Hello World!", 24, sf::Color::White, {400, 300});

    while (window.isOpen())
    {
        detectContinuousMovement();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            detectAttack(event);
            detectMouseClick(event);

            window.clear(sf::Color::Black);

            // draw everything here
            // window.draw(...)
            window.draw(rectangle);
            window.draw(circle);
            window.draw(text);

            //end the current frame
            window.display();
        }
    }
}

void detectAttack(const std::optional<sf::Event> &event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Space key pressed (ATTACK)" << std::endl;
        }
    }
}

void detectMouseClick(const std::optional<sf::Event> &event)
{
    if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            std::cout << "Left mouse button pressed" << std::endl;
            std::cout << "Mouse coordinates at the point of left click: " << mouseButtonPressed->position.x << "," <<
                mouseButtonPressed->position.y << std::endl;
        } else if (mouseButtonPressed->button == sf::Mouse::Button::Right)
        {
            std::cout << "Right mouse button pressed" << std::endl;
            std::cout << "Mouse coordinates at the point of right click: " << mouseButtonPressed->position.x << "," <<
                mouseButtonPressed->position.y << std::endl;
        }
    }
}

void detectContinuousMovement()
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
