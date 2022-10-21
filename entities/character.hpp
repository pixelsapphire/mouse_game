#ifndef MOUSE_GAME_CHARACTER
#define MOUSE_GAME_CHARACTER

#include <SFML/Graphics.hpp>

#include "entities/animatable.hpp"

namespace mg {

    class character : public sf::RectangleShape, public animatable {

    protected:

        sf::Vector2f velocity = {0, 0};
        int hp = 0;

    public:

        void animate(float delta_time) override {}

        void damage(int damage) {
            hp -= damage;
            setFillColor(sf::Color::Red);
        }

        bool is_alive() const {
            return hp > 0;
        }
    };
}

#endif //MOUSE_GAME_CHARACTER
