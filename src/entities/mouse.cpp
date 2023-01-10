#include <SFML/Graphics.hpp>

#include <definitions.hpp>
#include <entities/character.hpp>
#include <entities/item.hpp>
#include <game/scene.hpp>
#include <world/trigger.hpp>
#include <entities/mouse.hpp>

namespace mg {

    mouse::mouse(const sf::Vector2f& position) {
        setTexture(&textures["entity.mouse"]);
        setSize({26, 26});
        setPosition(position);
        hp = 5;
    }

    bool mouse::has_key() const {
        return inventory.key > 0;
    }

    void mouse::remove_key() {
        inventory.key--;
    }

    const struct inventory& mouse::get_inventory() const {
        return inventory;
    }

    void mouse::set_scene(scene& world) {
        objects = &world.get_objects();
    }

    void mouse::oof() {
        hp = 0;
    }

    void mouse::animate(float delta_time) {

        update_damage_cooldown();

        velocity.y += gravity_acceleration * delta_time;

        const sf::Vector2f player_size = getSize();
        const float player_bottom = getPosition().y + player_size.y;
        const float player_left = getPosition().x;
        const float player_right = getPosition().x + player_size.x;

        bool can_jump = false;
        bool can_move_left = true;
        bool can_move_right = true;

        for (sf::Drawable* object : *objects) {

            const auto p = dynamic_cast<platform*>(object);
            auto l = dynamic_cast<trigger*>(object);

            if (p != nullptr) {

                const float platform_top = p->getGlobalBounds().top;
                const float platform_left = p->getPosition().x;
                const float platform_right = p->getPosition().x + p->getSize().x;

                const collision_axis collision = aabb_collision(*this, velocity * delta_time, *p);

                if (collision == collision_axis::y and player_bottom <= platform_top) {
                    velocity.y = 0;
                    setPosition({getPosition().x, platform_top - player_size.x});
                    can_jump = true;
                } else if (collision == collision_axis::x or collision == collision_axis::both) {
                    if (player_right >= platform_left and player_left <= platform_left) can_move_right = false;
                    if (player_left <= platform_right and player_right >= platform_right) can_move_left = false;
                }

            } else if (l != nullptr) {
                const bool touching = l->getGlobalBounds().findIntersection(getGlobalBounds()).has_value();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) and touching) l->switch_on();
            }
        }

        velocity.x = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and can_move_left) velocity.x -= forward_speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) and can_move_right) velocity.x += forward_speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and can_jump) velocity.y = -jump_speed;

        if (velocity.x < 0 and not inverted) {
            inverted = true;
            setTexture(&textures["entity.mouse_flipped"]);
        } else if (velocity.x > 0 and inverted) {
            inverted = false;
            setTexture(&textures["entity.mouse"]);
        }

        move(velocity * delta_time);

        for (sf::Drawable* object : *objects) {
            auto i = dynamic_cast<item*>(object);
            if (i != nullptr) {
                const bool touching_item = i->getGlobalBounds().findIntersection(getGlobalBounds()).has_value();
                if (touching_item) {
                    i->damage(1);
                    if (i->get_type() == item_type::cheese) inventory.cheese++;
                    else if (i->get_type() == item_type::key) inventory.key++;
                    else if (i->get_type() == item_type::heart) hp++;
                }
            }
        }
    }
}
