#ifndef MOUSE_GAME_BULLET
#define MOUSE_GAME_BULLET

#include <SFML/Graphics.hpp>

#include "mouse.hpp"

class bullet : public sf::CircleShape {

    sf::Vector2f velocity = {-100, 0}; // px / s

public:

    bullet(sf::Color color, sf::Vector2f initial_position) {
        setFillColor(color);
        setRadius(2.5);
        setOrigin({2.5, 2.5});
        setPosition(initial_position);
    }

    void behavior(float delta_time, mouse& player) {
        move(velocity * delta_time);
        if (getGlobalBounds().findIntersection(player.getGlobalBounds()).has_value()) {
            setPosition({-100, -100});
            player.damage(20);
        }
    }
};

#endif //MOUSE_GAME_BULLET
