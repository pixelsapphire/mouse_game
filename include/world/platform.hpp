#ifndef MOUSE_GAME_PLATFORM
#define MOUSE_GAME_PLATFORM

#include <SFML/Graphics.hpp>

namespace mg {

    class platform : public sf::RectangleShape {

    public:

        platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color);

        platform(float width, const sf::Vector2f& position, const sf::Color& color);
    };
}

#endif //MOUSE_GAME_PLATFORM