#ifndef MOUSE_GAME_MOVING_PLATFORM
#define MOUSE_GAME_MOVING_PLATFORM

#include <SFML/Graphics.hpp>
#include <entities/animatable.hpp>
#include <world/platform.hpp>

namespace mg {

    class moving_platform : public platform, public animatable {

        constexpr static float velocity = 50;
        sf::Vector2f target;

    public:

        moving_platform(sf::Vector2f size, sf::Vector2f position, const sf::Color& color);

        moving_platform(float width, sf::Vector2f position, const sf::Color& color);

        void set_point(sf::Vector2f point);

        void animate(float delta_time) override;
    };
}

#endif //MOUSE_GAME_MOVING_PLATFORM