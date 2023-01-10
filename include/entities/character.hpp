#ifndef MOUSE_GAME_CHARACTER
#define MOUSE_GAME_CHARACTER

#include <SFML/Graphics.hpp>

#include <entities/animatable.hpp>

namespace mg {

    class character : public sf::RectangleShape, public animatable {

    protected:

        sf::Clock clock;
        sf::Vector2f velocity = {0, 0};
        int hp = 0;

    public:

        void animate(float delta_time) override;

        void damage(int damage);

        int get_hp() const;

        void update_damage_cooldown();

        bool is_alive() const;
    };
}

#endif //MOUSE_GAME_CHARACTER
