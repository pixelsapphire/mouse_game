#include <iostream>
#include <SFML/Graphics.hpp>

#include <assets.hpp>
#include <entities/bullet.hpp>
#include <entities/enemy.hpp>

namespace mg {

    enemy::enemy(sf::Vector2f position, mouse& player, float shoot_delay) : player(player), shoot_delay(shoot_delay) {
        setTexture(&textures["entity.cat_the_enemy"]);
        setSize({48, 48});
        setPosition(position);
        hp = 20;
        shoot_clock.restart();
    }

    void enemy::shoot(std::list<sf::Drawable*>& objects) {
        if (not first_shoot or shoot_clock.getElapsedTime().asSeconds() >= shoot_delay) {
            first_shoot = true;
            objects.push_back(new bullet({255, 128, 0}, getPosition() + getSize() / 2.0f, player));
            shoot_clock.restart();
        }
    }
}
