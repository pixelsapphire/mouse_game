#include <SFML/Graphics.hpp>
#include <assets.hpp>
#include <world/portal.hpp>

namespace mg {

    portal::portal(const sf::Vector2f& position, const sf::Color& color) : sf::RectangleShape({64, 110}) {
        setPosition(position);
        setFillColor(color);
        setTexture(&textures["env.portal"]);
    }
}
