#include <game/game_context.hpp>
#include <scenes/initial_scene.hpp>
#include <SFML/Graphics.hpp>

namespace mg {

    game_context::game_context() : window(sf::VideoMode({1280, 768}), "Mouse Game") {
        window.setVerticalSyncEnabled(true);
        window.setView(view);
        clock.restart();
    }

    void game_context::set_scene(scene& scene) {
        current_scene = &scene;
    }

    mouse& game_context::get_player() {
        return player;
    }

    void game_context::start_game() {
        bool game_over = false;
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();
                else if (event.type == sf::Event::Resized) window.setSize({1280, 768});
            }
            window.clear(sf::Color::Black);

            const float delta_time = clock.getElapsedTime().asSeconds();
            if (not current_scene->is_ded()) {
                current_scene->update(delta_time, *this);
                hud.update();
            } else if (not game_over) {
                game_over = true;
                sounds["sfx.game_over"].play();
                window.setFramerateLimit(1);
            }

            window.draw(current_scene->get_background());
            window.draw(*current_scene);
            window.draw(hud);

            clock.restart();
            window.display();
        }
    }

    void game_context::move_player(float delta_time) {
        const auto x_pos1 = player.getPosition().x;
        player.animate(delta_time);
        const auto x_pos2 = player.getPosition().x;
        sf::View new_view = window.getView();
        if (x_pos2 >= float(window.getSize().x) / 2) {
            const sf::Vector2f offset = {x_pos2 - x_pos1, 0.0f};
            new_view.move(offset);
            current_scene->get_background().move(offset);
            hud.move(offset);
        }
        window.setView(new_view);
    }

    void game_context::finish_level() {
        // TODO Display some kind of "level complete" message with time and a "return" button which takes the player to the level selection menu
    }
}