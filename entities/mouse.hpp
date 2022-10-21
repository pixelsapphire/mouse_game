#ifndef MOUSE_GAME_MOUSE
#define MOUSE_GAME_MOUSE

#include <iostream>

#include <SFML/Graphics.hpp>

#include "entities/character.hpp"
#include "entities/platform.hpp"

namespace mg {

    class mouse : public character {

        float gravity = 981;
        const std::vector<platform>& platforms;

    public:

        mouse(sf::Vector2f position, const std::vector<platform>& platforms) : platforms(platforms) {
            setFillColor(sf::Color(64, 64, 64));
            setSize({20, 20});
            setPosition(position);
            hp = 60;
        }

        void animate(float delta_time) override {
            velocity.y += gravity * delta_time;
            const float player_left = getPosition().x;
            const float player_right = getPosition().x + 20;
            bool can_jump = false;
            for (const platform& p : platforms) {

                const float platform_top = p.getGlobalBounds().top;
                const float platform_bottom = platform_top + p.getSize().y;
                const float platform_left = p.getPosition().x;
                const float platform_right = p.getPosition().x + p.getSize().x;

                const float player_top = getPosition().y;
                const float player_bottom = player_top + 20;
                const float delta_y = velocity.y * delta_time;
                const float player_future_bottom = player_bottom + delta_y;

                if (player_future_bottom > platform_top and player_top < platform_bottom and
                    player_left < platform_right and player_right > platform_left)
                    velocity.y = 0;

                if (player_bottom + 1 > platform_top
                    and player_left < platform_right and player_right > platform_left)
                    can_jump = true;
            }
            controls(can_jump);
            move(velocity * delta_time);
        }

        // TODO Block movement through platforms in the X axis
        void controls(bool can_jump) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and can_jump) velocity.y = -450;
            float velocity_x = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity_x -= 200;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity_x += 200;
            velocity.x = velocity_x;
        }
    };
}

#endif //MOUSE_GAME_MOUSE