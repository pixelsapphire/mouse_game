#ifndef MOUSE_GAME_ENEMY
#define MOUSE_GAME_ENEMY

#include <iostream>
#include <SFML/Graphics.hpp>

#include "bullet.hpp"
#include "character.hpp"

class enemy : public character {

public:

    explicit enemy(sf::Vector2f position) {
        setFillColor(sf::Color(255, 0, 0));
        setSize({30, 30});
        setPosition(position);
        hp = 20;
    }

    void shoot(std::vector<bullet>& bullets) {
        bullets.push_back(bullet({255, 128, 0}, getPosition() + getSize() / 2.0f));
    }
};

#endif //MOUSE_GAME_ENEMY
