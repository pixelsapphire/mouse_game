#include <vector>
#include <SFML/Graphics.hpp>
#include <scenes/second_scene.hpp>

namespace mg {

    second_scene::second_scene(mouse& player) : scene(&player) {

        set_background(textures["background.deep_blue"]);
        set_platform_color({24, 28, 48});
        setup_portal({1850, 250}, sf::Color(45, 59, 114), sf::Color(60, 93, 183));
//        setup_portal({200, 200}, sf::Color(45, 59, 114), sf::Color(60, 93, 183));
        player.setPosition({150, 250});

        add_platform(250, {0, 300});
        add_platform(200, {360, 220});
        add_platform(150, {500, 400});
        add_platform(100, {360, 500});
        add_platform(50, {600, 500});
        add_platform({24, 260}, {360, 242});
        add_platform(100, {700, 425});
        add_platform(300, {825, 325});
        add_platform(150, {750, 230});
        add_platform(100, {1200, 450});
        add_object(cheese_elevator = new moving_platform(150, {1300, 150}, get_platform_color()));
        add_platform(150, {1000, 550});
        add_platform(100, {1300, 550});
        add_platform(200, {1600, 350});

        add_object(new trigger(trigger_type::lever, {1050, 550 - 48}, [&]() {
            cheese_elevator->set_point({1300, 350});
            return true;
        }));

        add_object(new enemy({605, 500 - 46}, player, 2));
        add_object(new enemy({785, 220 - 36}, player, 3.5));
        add_object(new enemy({1350, 550 - 48}, player, 3));

        add_object(heart1 = new item(item_type::heart, {990, 50}, objects, true));
        add_object(new item(item_type::cheese, {450, 100}, objects, true));
        add_object(new item(item_type::cheese, {400, 400}, objects, true));
        add_object(new item(item_type::cheese, {1350, 100}, objects, true));
    }

    void second_scene::update(float delta_time, game_context& context) {
        scene::update(delta_time, context);
    }
}

