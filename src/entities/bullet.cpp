#include <SFML/Graphics.hpp>

#include <entities/animatable.hpp>
#include <entities/mouse.hpp>
#include <entities/bullet.hpp>

namespace mg {

    bullet::bullet(sf::Color color, sf::Vector2f initial_position, mouse& player) : player(player) {
        setFillColor(color);
        setRadius(2.5);
        setOrigin({2.5, 2.5});
        setPosition(initial_position);
    }

    void bullet::animate(float delta_time) {
        move(velocity * delta_time);
        if (getGlobalBounds().findIntersection(player.getGlobalBounds()).has_value()) {
            setPosition({-100, -100});
            player.damage(1);
        }
    }
}