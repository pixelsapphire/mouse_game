#ifndef MOUSE_GAME_BULLET
#define MOUSE_GAME_BULLET

#include <SFML/Graphics.hpp>

#include <entities/animatable.hpp>
#include <entities/mouse.hpp>

namespace mg {

    class bullet : public sf::CircleShape, public animatable {

        sf::Vector2f velocity = {-100, 0};
        mouse& player;

    public:

        bullet(sf::Color color, sf::Vector2f initial_position, mouse& player);

        void animate(float delta_time) override;
    };
}

#endif //MOUSE_GAME_BULLET
