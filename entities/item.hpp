#ifndef MOUSE_GAME_ITEM
#define MOUSE_GAME_ITEM

#include <SFML/Graphics.hpp>
#include "assets.hpp"
#include "character.hpp"
#include "definitions.hpp"
#include "utility/collision.hpp"
#include "world/platform.hpp"

namespace mg {

    enum item_type {
        key, cheese, heart
    };

    class item : public character {

        item_type type;
        const std::vector<platform>* platforms;
        bool gravity_affected = false;

    public:

        item(item_type type, sf::Vector2f position, std::vector<platform>& platforms, bool has_gravity = false)
                : type(type), platforms(&platforms), gravity_affected(has_gravity) {

            if (type == item_type::key) setTexture(&textures::item_key);
            else if (type == item_type::cheese) setTexture(&textures::item_cheese);
            // else if (type == item_type::heart) setTexture(textures::item_heart);

            setSize({32, 32});
            setPosition(position);
            hp = 1;
        }

        void set_gravity_affected(bool gravity) {
            gravity_affected = gravity;
        }

        item_type get_type() const {
            return type;
        }

        void animate(float delta_time) override {
            if (gravity_affected) {

                velocity.y += gravity_acceleration * delta_time;

                const sf::Vector2f item_size = getSize();
                const float item_bottom = getPosition().y + item_size.y;

                for (const platform& p : *platforms) {

                    const float platform_top = p.getGlobalBounds().top;

                    const collision_axis collision = aabb_collision(*this, velocity * delta_time, p);

                    if (collision == collision_axis::y and item_bottom <= platform_top) {
                        velocity.y = 0;
                        setPosition({getPosition().x, platform_top - item_size.x});
                    }
                }

                move(velocity * delta_time);
            }
        }
    };
}

#endif //MOUSE_GAME_ITEM
