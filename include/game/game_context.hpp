#ifndef MOUSE_GAME_GAME_CONTEXT
#define MOUSE_GAME_GAME_CONTEXT

#include <SFML/Graphics.hpp>

#include <entities/bullet.hpp>
#include <entities/mouse.hpp>
#include <game/hud.hpp>

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

        game_context();

        void set_scene(scene& scene);

        mouse& get_player();

        void start_game();

        void move_player(float delta_time);
    };
}

#endif //MOUSE_GAME_GAME_CONTEXT
