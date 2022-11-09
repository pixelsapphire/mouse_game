#ifndef MOUSE_GAME_INITIAL_SCENE
#define MOUSE_GAME_INITIAL_SCENE

#include <vector>

#include <SFML/Graphics.hpp>

#include "entities/bullet.hpp"
#include "entities/enemy.hpp"
#include "entities/item.hpp"
#include "entities/mouse.hpp"
#include "game/scene.hpp"
#include "world/lever.hpp"
#include "world/platform.hpp"

namespace mg {

    class initial_scene : public scene {

        std::vector<platform> platforms;
        std::vector<enemy> enemies;
        std::vector<bullet> bullets;
        std::vector<lever> levers;
        std::vector<item> items;
        mouse player{{0, 0}, platforms, levers, items};
        sf::Color background_color{64, 128, 196};
        sf::Clock shoot_clock;
        bool key_released = false;

        void release_key() {
            if (not key_released) {
                std::cout << "Key released!" << std::endl;
                key_released = true;
                items[0].set_gravity_affected(true);
            }
        }

    public:

        initial_scene() {
//            platforms.push_back(platform(40, {444, 430}));
//            platforms.push_back(platform(128, {400, 450}));
//            platforms.push_back(platform(128, {550, 400}));
//            platforms.push_back(platform(96, {700, 300}));
//            platforms.push_back(platform(96, {700, 220}));

            platforms.push_back(platform(300, {0, 500}));
            platforms.push_back(platform(230, {350, 450}));
            platforms.push_back(platform(200, {600, 600}));
            platforms.push_back(platform(100, {770, 500}));
            platforms.push_back(platform(100, {850, 425}));
            platforms.push_back(platform(350, {825, 325}));
            platforms.push_back(platform(150, {750, 230}));
            levers.push_back(lever({780, 206}, [&]() { release_key(); }));
            items.push_back(item(item_type::key, {460, -50}, platforms));
            items.push_back(item(item_type::cheese, {700, 560}, platforms, true));

            shoot_clock.restart();
        }

        void set_player_position(float x, float y) {
            player.setPosition({x, y});
        }

        void update(float delta_time, sf::RenderWindow& window) override {

            const auto x_pos1 = player.getPosition().x;
            player.animate(delta_time);
            const auto x_pos2 = player.getPosition().x;
            sf::View view = window.getView();
            if (x_pos2 >= float(window.getSize().x) / 2) view.move({x_pos2 - x_pos1, 0.0f});
            window.setView(view);

            std::erase_if(items, [&](item& i) { return not i.is_alive(); });

            if (shoot_clock.getElapsedTime().asSeconds() >= 2) {
                for (enemy& e : enemies) e.shoot(bullets);
                shoot_clock.restart();
            }
            for (bullet& b : bullets) b.animate(delta_time);
            for (item& i : items) i.animate(delta_time);

            if (not player.is_alive()) {
                std::cout << "GAME OVER" << std::endl;
                exit(0);
            }
        }

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override {
            for (const bullet& b : bullets) target.draw(b);
            for (const platform& p : platforms) target.draw(p);
            for (const enemy& e : enemies) target.draw(e);
            for (const lever& l : levers) target.draw(l);
            for (const item& i : items) target.draw(i);
            target.draw(player);
        }

        const sf::Color& get_background_color() const override {
            return background_color;
        }
    };
}

#endif //MOUSE_GAME_INITIAL_SCENE
