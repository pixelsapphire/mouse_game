#include <SFML/Graphics.hpp>
#include <world/platform.hpp>

namespace mg {

    platform::platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color)
            : sf::RectangleShape(size) {
        setPosition(position);
        setFillColor(color);
        setOutlineColor(sf::Color::Black);
        setOutlineThickness(-2);
    }

    platform::platform(float width, const sf::Vector2f& position, const sf::Color& color)
            : platform({width, 24}, position, color) {}
}
