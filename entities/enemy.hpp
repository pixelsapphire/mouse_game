#ifndef MOUSE_GAME_ENEMY
#define MOUSE_GAME_ENEMY

#include <iostream>
#include <SFML/Graphics.hpp>

#include "entities/bullet.hpp"
#include "entities/character.hpp"
#include "entities/mouse.hpp"

namespace mg {

    class enemy : public character {

        mouse& player;

    public:

        explicit enemy(sf::Vector2f position, mouse& player) : player(player) {
            setFillColor(sf::Color(255, 0, 0));
            setSize({30, 30});
            setPosition(position);
            hp = 20;
        }

        void shoot(std::vector<bullet>& bullets) {
            bullets.push_back(bullet({255, 128, 0}, getPosition() + getSize() / 2.0f, player));
        }
    };
}

#endif //MOUSE_GAME_ENEMY
