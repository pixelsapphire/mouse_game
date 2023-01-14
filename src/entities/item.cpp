#include <list>
#include <SFML/Graphics.hpp>
#include <assets.hpp>
#include <entities/character.hpp>
#include <definitions.hpp>
#include <utility/collision.hpp>
#include <world/platform.hpp>
#include <entities/item.hpp>

namespace mg {

    item::item(item_type type, sf::Vector2f position, const std::list<sf::Drawable*>& objects, bool has_gravity)
            : type(type), objects(objects), gravity_affected(has_gravity) {

        if (type == item_type::key) setTexture(&textures["item.key"]);
        else if (type == item_type::cheese) setTexture(&textures["item.cheese"]);
        else if (type == item_type::heart) setTexture(&textures["item.heart"]);

        setSize({32, 32});
        setPosition(position);
        hp = 1;
    }

    void item::set_gravity_affected(bool gravity) {
        gravity_affected = gravity;
    }

    item_type item::get_type() const {
        return type;
    }

    void item::animate(float delta_time) {
        if (gravity_affected) {

            velocity.y += gravity_acceleration * delta_time;

            const sf::Vector2f item_size = getSize();
            const float item_bottom = getPosition().y + item_size.y;

            for (const sf::Drawable* o : objects) {
                const auto p = dynamic_cast<const platform*>(o);
                if (p != nullptr) {

                    const float platform_top = p->getGlobalBounds().top;

                    const collision_axis collision = aabb_collision(*this, velocity * delta_time, *p);

                    if (collision == collision_axis::y and item_bottom <= platform_top) {
                        velocity.y = 0;
                        setPosition({getPosition().x, platform_top - item_size.x});
                    }
//                    if (getGlobalBounds().findIntersection(p->getGlobalBounds()).has_value() and velocity.y > 0) {
//                        setPosition({getPosition().x, p->getGlobalBounds().top - item_size.y});
//                        velocity.y = 0;
//                    }
                }
            }

            move(velocity * delta_time);
        }
    }
}
