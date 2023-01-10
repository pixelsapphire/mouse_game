#ifndef MOUSE_GAME_INITIAL_SCENE
#define MOUSE_GAME_INITIAL_SCENE

#include <vector>

#include <SFML/Graphics.hpp>

#include <entities/bullet.hpp>
#include <entities/enemy.hpp>
#include <entities/item.hpp>
#include <entities/mouse.hpp>
#include <game/game_context.hpp>
#include <game/scene.hpp>
#include <world/trigger.hpp>
#include <world/moving_platform.hpp>
#include <world/platform.hpp>
#include <world/portal.hpp>

namespace mg {

    class initial_scene : public scene {

        sf::Color background_color{64, 128, 196};
        bool key_released = false;

        item* key1;
        moving_platform* door1;

        void release_key();

        void add_platform(float width, const sf::Vector2f& position);

    public:

        explicit initial_scene(mouse& player);
    };
}

#endif //MOUSE_GAME_INITIAL_SCENE
