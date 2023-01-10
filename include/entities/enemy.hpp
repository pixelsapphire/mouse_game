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

        mouse& player;

    public:

        explicit enemy(sf::Vector2f position, mouse& player);

        void shoot(std::list<sf::Drawable*>& objects);
    };
}

#endif //MOUSE_GAME_ENEMY
