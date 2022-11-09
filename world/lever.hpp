#ifndef MOUSE_GAME_LEVER
#define MOUSE_GAME_LEVER

#include <SFML/Graphics.hpp>
#include <utility>

namespace mg {

    class lever : public sf::RectangleShape {

        std::function<void()> on_activate;

    public:

        lever(sf::Vector2f position, std::function<void()> on_activate) : on_activate(std::move(on_activate)) {
            setFillColor(sf::Color(240, 0, 64));
            setSize({24, 24});
            setPosition(position);
        }

        void switch_on() {
            setFillColor(sf::Color(0, 196, 64));
            on_activate();
        }
    };
}

#endif //MOUSE_GAME_LEVER
