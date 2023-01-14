#ifndef MOUSE_GAME_ENEMY
#define MOUSE_GAME_ENEMY

#include <iostream>
#include <SFML/Graphics.hpp>

#include <assets.hpp>
#include <entities/bullet.hpp>
#include <entities/character.hpp>
#include <entities/mouse.hpp>

namespace mg {

    class enemy : public character {

        sf::Clock shoot_clock;
        float shoot_delay;
        bool first_shoot = false;
        mouse& player;

    public:

        enemy(sf::Vector2f position, mouse& player, float shoot_delay);

        void shoot(std::list<sf::Drawable*>& objects);
    };
}

#endif //MOUSE_GAME_ENEMY
