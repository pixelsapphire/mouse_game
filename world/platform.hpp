#ifndef MOUSE_GAME_PLATFORM
#define MOUSE_GAME_PLATFORM

#include <SFML/Graphics.hpp>

namespace mg {

    class platform : public sf::RectangleShape {

    public:

        platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color) : sf::RectangleShape(size) {
            setPosition(position);
            setFillColor(color);
            setOutlineColor(sf::Color::Black);
            setOutlineThickness(-2);
        }

        platform(float width, const sf::Vector2f& position, const sf::Color& color) : platform({width, 24}, position, color) {}
    };
}

#endif //MOUSE_GAME_PLATFORM