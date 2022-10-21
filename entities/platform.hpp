#ifndef MOUSE_GAME_PLATFORM
#define MOUSE_GAME_PLATFORM

#include <SFML/Graphics.hpp>

namespace mg {

    class platform : public sf::RectangleShape {

    public:

        platform(float width, sf::Vector2f position) {
            setFillColor(sf::Color(0, 196, 64));
            setSize({width, 20});
            setPosition(position);
        }
    };
}

#endif //MOUSE_GAME_PLATFORM