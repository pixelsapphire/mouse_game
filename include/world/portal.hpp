#ifndef MOUSE_GAME_PORTAL
#define MOUSE_GAME_PORTAL

#include <SFML/Graphics.hpp>
#include <assets.hpp>

namespace mg {

    class portal : public sf::RectangleShape {

    public:

        portal(const sf::Vector2f& position, const sf::Color& color);
    };
}

#endif //MOUSE_GAME_PORTAL
