#ifndef MOUSE_GAME_SECOND_SCENE
#define MOUSE_GAME_SECOND_SCENE

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

    class second_scene : public scene {

        sf::Color background_color{64, 128, 196};
        bool key_released = false;
        moving_platform* cheese_elevator;

        item* heart1;

        bool hint_avoid_added = false, hint_cheese_added = false, hint_keyhole_added = false, hint_lever_added = false;

    public:

        explicit second_scene(mouse& player);

        void update(float delta_time, game_context& context) override;
    };
}

#endif //MOUSE_GAME_SECOND_SCENE
