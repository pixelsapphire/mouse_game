#ifndef MOUSE_GAME_BULLET
#define MOUSE_GAME_BULLET

#include <SFML/Graphics.hpp>

#include "entities/animatable.hpp"
#include "entities/mouse.hpp"

namespace mg {

    class bullet : public sf::CircleShape, public animatable {

        sf::Vector2f velocity = {-100, 0};
        mouse& player;

    public:

        bullet(sf::Color color, sf::Vector2f initial_position, mouse& player) : player(player) {
            setFillColor(color);
            setRadius(2.5);
            setOrigin({2.5, 2.5});
            setPosition(initial_position);
        }

        void animate(float delta_time) override {
            move(velocity * delta_time);
            if (getGlobalBounds().findIntersection(player.getGlobalBounds()).has_value()) {
                setPosition({-100, -100});
                player.damage(20);
            }
        }
    };
}

#endif //MOUSE_GAME_BULLET
