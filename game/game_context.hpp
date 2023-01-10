#ifndef MOUSE_GAME_GAME_CONTEXT
#define MOUSE_GAME_GAME_CONTEXT

#include <SFML/Graphics.hpp>

#include "entities/mouse.hpp"
#include "game/hud.hpp"

namespace mg {

    class game_context {

        sf::RenderWindow window;
        sf::Event event{};
        sf::Clock clock;
        mouse player{{0, 0}};
        scene* current_scene = nullptr;
        hud hud{player};
        sf::View view{sf::FloatRect({0, 0}, {1280, 768})};

    public:

        game_context() : window(sf::VideoMode({1280, 768}), "Mouse Game") {
            window.setVerticalSyncEnabled(true);
            window.setView(view);
            clock.restart();
        }

        void set_scene(scene& scene) {
            current_scene = &scene;
        }

        mouse& get_player() {
            return player;
        }

        void start_game() {
            bool game_over = false;
            while (window.isOpen()) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) window.close();
                    else if (event.type == sf::Event::Resized) window.setSize({1280, 768});
                }
                window.clear(current_scene->get_background_color());

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

        void move_player(float delta_time) {
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
    };
}

#endif //MOUSE_GAME_GAME_CONTEXT
