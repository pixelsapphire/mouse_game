#ifndef MOUSE_GAME_MOUSE
#define MOUSE_GAME_MOUSE

#include <iostream>

#include <SFML/Graphics.hpp>

#include "definitions.hpp"
#include "entities/character.hpp"
#include "entities/item.hpp"
#include "utility/collision.hpp"
#include "world/lever.hpp"
#include "world/platform.hpp"

namespace mg {

    struct inventory {
        uint16_t cheese = 0, key = 0;
    };

    class mouse : public character {

        const float forward_speed = 200, jump_speed = 450;
        inventory inventory;
        const std::vector<platform>& platforms;
        std::vector<lever>& levers;
        std::vector<item>& items;

    public:

        mouse(sf::Vector2f position, const std::vector<platform>& platforms, std::vector<lever>& levers,
              std::vector<item>& items)
                : platforms(platforms), levers(levers), items(items) {
            setFillColor(sf::Color(64, 64, 64));
            setSize({20, 20});
            setPosition(position);
            hp = 60;
        }

        void animate(float delta_time) override {

            velocity.y += gravity_acceleration * delta_time;

            const sf::Vector2f player_size = getSize();
            const float player_bottom = getPosition().y + player_size.y;
            const float player_left = getPosition().x;
            const float player_right = getPosition().x + player_size.x;

            bool can_jump = false;
            bool can_move_left = true;
            bool can_move_right = true;

            for (const platform& p : platforms) {

                const float platform_top = p.getGlobalBounds().top;
                const float platform_left = p.getPosition().x;
                const float platform_right = p.getPosition().x + p.getSize().x;

                const collision_axis collision = aabb_collision(*this, velocity * delta_time, p);

                if (collision == collision_axis::y and player_bottom <= platform_top) {
                    velocity.y = 0;
                    setPosition({getPosition().x, platform_top - player_size.x});
                    can_jump = true;
                } else if (collision == collision_axis::x or collision == collision_axis::both) {
                    if (player_right >= platform_left and player_left <= platform_left) can_move_right = false;
                    if (player_left <= platform_right and player_right >= platform_right) can_move_left = false;
                }
            }

            for (lever& l : levers) {
                const bool touching = l.getGlobalBounds().findIntersection(getGlobalBounds()).has_value();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) and touching) l.switch_on();
            }

            velocity.x = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and can_move_left) velocity.x -= forward_speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) and can_move_right) velocity.x += forward_speed;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and can_jump) velocity.y = -jump_speed;

            move(velocity * delta_time);

            for (item& i : items) {
                const bool touching_item = i.getGlobalBounds().findIntersection(getGlobalBounds()).has_value();
                if (touching_item) {
                    std::cout << "mouse collected an item" << std::endl;
                    i.damage(1);
                    if (i.get_type() == item_type::cheese) inventory.cheese++;
                    else if (i.get_type() == item_type::key) inventory.key++;
                    else if (i.get_type() == item_type::heart) hp++;
                }
            }
        }
    };
}

#endif //MOUSE_GAME_MOUSE