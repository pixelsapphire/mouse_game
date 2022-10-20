#include <SFML/Graphics.hpp>

#include "scene.hpp"

int main() {

    sf::RenderWindow window{sf::VideoMode{{1280, 768}}, "Mouse Game"};
    window.setVerticalSyncEnabled(true);
    sf::Event event{};
    sf::Clock clock;
    clock.restart();

    scene level_1_scene;
    level_1_scene.set_player_position(450, 400);
    level_1_scene.set_background_color(sf::Color(64, 128, 196));

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::Resized) window.setSize({1280, 768});
        }
        window.clear(level_1_scene.get_background_color());

        const float delta_time = clock.getElapsedTime().asSeconds(); // ~16.67 ms
        level_1_scene.animate(delta_time);
        window.draw(level_1_scene);

        clock.restart();
        window.display();
    }

    return 0;
}
