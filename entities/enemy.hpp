#ifndef MOUSE_GAME_ENEMY
#define MOUSE_GAME_ENEMY

#include <iostream>
#include <SFML/Graphics.hpp>

#include "assets.hpp"
#include "entities/bullet.hpp"
#include "entities/character.hpp"
#include "entities/mouse.hpp"

namespace mg {

    class enemy : public character {

        mouse& player;

    public:

        explicit enemy(sf::Vector2f position, mouse& player) : player(player) {
            setTexture(&textures["entity.cat_the_enemy"]);
            setSize({48, 48});
            setPosition(position);
            hp = 20;
        }

        void shoot(std::list<sf::Drawable*>& objects) {
            objects.push_back(new bullet({255, 128, 0}, getPosition() + getSize() / 2.0f, player));
        }
    };
}

#endif //MOUSE_GAME_ENEMY
