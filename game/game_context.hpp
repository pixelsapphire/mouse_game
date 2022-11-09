#ifndef MOUSE_GAME_GAME_CONTEXT
#define MOUSE_GAME_GAME_CONTEXT

#include <SFML/Graphics.hpp>

#include "game/scene.hpp"

namespace mg {

    class game_context {

        sf::RenderWindow window;
        sf::Event event{};
        sf::Clock clock;
        scene* current_scene = nullptr;
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

        void start_game() {
            while (window.isOpen()) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) window.close();
                    else if (event.type == sf::Event::Resized) window.setSize({1280, 768});
                }
                window.clear(current_scene->get_background_color());

                const float delta_time = clock.getElapsedTime().asSeconds();
                current_scene->update(delta_time, window);

                window.draw(*current_scene, sf::RenderStates::Default);

                clock.restart();
                window.display();
            }
        }
    };
}

#endif //MOUSE_GAME_GAME_CONTEXT
