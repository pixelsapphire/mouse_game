#include <scenes/initial_scene.hpp>
#include <vector>

#include <SFML/Graphics.hpp>

namespace mg {

    void initial_scene::release_key() {
        if (not key_released) {
            key_released = true;
            key1->set_gravity_affected(true);
        }
    }

    initial_scene::initial_scene(mouse& player) : scene(&player) {

        set_background(textures["background.purple"]);
        set_platform_color({96, 48, 128});
        setup_portal({1250, 250}, sf::Color(186, 86, 246), sf::Color(255, 97, 177));
        player.setPosition({150, 350});

        add_platform(300, {0, 500});
        add_platform(230, {350, 450});
        add_platform(200, {600, 600});
        add_platform(100, {770, 500});
        add_platform(100, {850, 425});
        add_platform(350, {825, 325});
        add_platform(150, {750, 230});

        add_object(new enemy({900, 425 - 45}, player, 2));

        add_object(new trigger(trigger_type::lever, {780, 182}, [&]() {
            release_key();
            return true;
        }));
        add_object(new trigger(trigger_type::keyhole, {1025, 301}, [&]() {
            if (not player.has_key()) return false;
            door1->set_point({1130, 0});
            player.remove_key();
            add_hint("Enter the portal to\nfinish the level.", {1200, 150});
            return true;
        }));

        add_object(door1 = new moving_platform({24, 200}, {1130, 125}, get_platform_color()));

        add_object(key1 = new item(item_type::key, {460, -50}, objects));
        add_object(new item(item_type::cheese, {700, 560}, objects, true));

        add_hint("Use A and D to move.\nUse W to jump.", {50, 550});
    }

    void initial_scene::update(float delta_time, game_context& context) {
        scene::update(delta_time, context);
        const auto player_pos = player->getPosition();
        if ((hint_clock.getElapsedTime().asSeconds() >= 4 or player_pos.x > 300) and not hint_avoid_added) {
            add_hint("Avoid incoming bullets.\nThey really hurt.", {250, 300});
            hint_avoid_added = true;
        }
        if (player_pos.x > 500 and not hint_cheese_added) {
            add_hint("Collect the cheese to unlock levels. Yum!", {470, 630});
            hint_cheese_added = true;
        }
        if (player_pos.y < 325 and not hint_keyhole_added) {
            add_hint("The door is locked.\nFind a way to open it.", {970, 350});
            hint_keyhole_added = true;
        }
        if (player_pos.y < 230 and not hint_lever_added) {
            add_hint("Use X to interact.", {690, 130});
            hint_lever_added = true;
        }
    }
}

