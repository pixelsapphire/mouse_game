#include <iostream>
#include <SFML/Graphics.hpp>

#include <assets.hpp>
#include <entities/bullet.hpp>
#include <entities/character.hpp>
#include <entities/mouse.hpp>
#include <entities/enemy.hpp>

namespace mg {

    enemy::enemy(sf::Vector2f position, mouse& player) : player(player) {
        setTexture(&textures["entity.cat_the_enemy"]);
        setSize({48, 48});
        setPosition(position);
        hp = 20;
    }

    void enemy::shoot(std::list<sf::Drawable*>& objects) {
        objects.push_back(new bullet({255, 128, 0}, getPosition() + getSize() / 2.0f, player));
    }
}


