#ifndef MOUSE_GAME_MOVING_PLATFORM
#define MOUSE_GAME_MOVING_PLATFORM

#include <SFML/Graphics.hpp>
#include "entities/animatable.hpp"
#include "platform.hpp"

namespace mg {

    class moving_platform : public platform, public animatable {

        constexpr static float velocity = 50;
        sf::Vector2f target;

    public:

        moving_platform(sf::Vector2f size, sf::Vector2f position, const sf::Color& color)
                : platform(size, position, color), target(position) {}

        moving_platform(float width, sf::Vector2f position, const sf::Color& color)
                : moving_platform({width, 24}, position, color) {}

        void set_point(sf::Vector2f point) {
            target = point;
        }

        void animate(float delta_time) override {
            const auto pos = getPosition();
            if (target != pos) {
                const sf::Vector2f direction = (target - pos) / std::hypot(target.x - pos.x, target.y - pos.y);
                move(direction * velocity * delta_time);
            }
        }
    };
}

#endif //MOUSE_GAME_MOVING_PLATFORM