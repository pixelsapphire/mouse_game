#ifndef MOUSE_GAME_MOUSE
#define MOUSE_GAME_MOUSE

#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include <definitions.hpp>
#include <entities/character.hpp>
#include <entities/item.hpp>
#include <game/scene.hpp>
#include <utility/collision.hpp>
#include <world/trigger.hpp>
#include <world/platform.hpp>

namespace mg {

    struct inventory {
        uint16_t cheese = 0, key = 0;
    };

    class mouse : public character {

        const float forward_speed = 200, jump_speed = 450;
        inventory inventory;
        std::list<sf::Drawable*>* objects;
        bool inverted = false, player_control = true;
        sf::Clock travel_clock;
        sf::Vector2f travel_target;

    public:

        explicit mouse(const sf::Vector2f& position);

        bool has_key() const;

        void remove_key();

        const struct inventory& get_inventory() const;

        void set_scene(scene& world);

        void oof();

        void animate(float delta_time) override;

        void enter_portal(const portal& portal);
    };
}

#endif //MOUSE_GAME_MOUSE