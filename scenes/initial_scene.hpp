#ifndef MOUSE_GAME_INITIAL_SCENE
#define MOUSE_GAME_INITIAL_SCENE

#include <vector>

#include <SFML/Graphics.hpp>

#include "entities/bullet.hpp"
#include "entities/enemy.hpp"
#include "entities/item.hpp"
#include "entities/mouse.hpp"
#include "game/game_context.hpp"
#include "game/scene.hpp"
#include "world/trigger.hpp"
#include "world/moving_platform.hpp"
#include "world/platform.hpp"
#include "world/portal.hpp"

namespace mg {

    class initial_scene : public scene {

        sf::Color background_color{64, 128, 196};
        sf::Clock shoot_clock;
        bool key_released = false;

        item* key1;
        moving_platform* door1;

        void release_key() {
            if (not key_released) {
                key_released = true;
                key1->set_gravity_affected(true);
            }
        }

        void add_platform(float width, const sf::Vector2f& position) {
            objects.push_back(new platform(width, position, get_platform_color()));
        }

    public:

        explicit initial_scene(mouse& player) : scene(&player) {

            set_background(textures["background"]);
            set_platform_color({96, 48, 128});

            add_platform(300, {0, 500});
            add_platform(230, {350, 450});
            add_platform(200, {600, 600});
            add_platform(100, {770, 500});
            add_platform(100, {850, 425});
            add_platform(350, {825, 325});
            add_platform(150, {750, 230});

            objects.push_back(new portal({1290, 250}, sf::Color(255, 180, 200)));

            objects.push_back(new enemy({900, 425 - 45}, player));

            objects.push_back(new trigger(trigger_type::lever, {780, 182}, [&]() {
                release_key();
                return true;
            }));
            objects.push_back(new trigger(trigger_type::keyhole, {1025, 301}, [&]() {
                if (not player.has_key()) return false;
                door1->set_point({1130, 0});
                player.remove_key();
                return true;
            }));

            objects.push_back(door1 = new moving_platform({24, 200}, {1130, 125}, get_platform_color()));

            objects.push_back(key1 = new item(item_type::key, {460, -50}, objects));
            objects.push_back(new item(item_type::cheese, {700, 560}, objects, true));

            shoot_clock.restart();
        }

        void update(float delta_time, game_context& context) override {

            context.move_player(delta_time);

            std::erase_if(objects, [&](sf::Drawable* i) {
                const auto c = dynamic_cast<character*>(i);
                if (c != nullptr) return not c->is_alive();
                return false;
            });

            if (shoot_clock.getElapsedTime().asSeconds() >= 2) {
                for (sf::Drawable* object : objects) {
                    const auto e = dynamic_cast<enemy*>(object);
                    if (e != nullptr) e->shoot(objects);
                }
                shoot_clock.restart();
            }
            for (sf::Drawable* object : objects) {
                const auto b = dynamic_cast<bullet*>(object);
                const auto i = dynamic_cast<item*>(object);
                const auto m = dynamic_cast<moving_platform*>(object);
                if (b != nullptr or i != nullptr or m != nullptr) dynamic_cast<animatable*>(object)->animate(delta_time);
            }

            if (player->getPosition().y > 768) player->oof();

            if (not player->is_alive()) ded = true;
        }

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override {
            for (const sf::Drawable* o : objects) target.draw(*o);
            target.draw(*player);
        }

        const sf::Color& get_background_color() const override {
            return background_color;
        }
    };
}

#endif //MOUSE_GAME_INITIAL_SCENE
