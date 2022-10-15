#ifndef MOUSE_GAME_SCENE
#define MOUSE_GAME_SCENE

#include <vector>

#include <SFML/Graphics.hpp>

#include "bullet.hpp"
#include "enemy.hpp"
#include "mouse.hpp"
#include "platform.hpp"

class scene : public sf::Drawable {

    mouse player{{0, 0}};
    std::vector<platform> platforms;
    std::vector<enemy> enemies;
    std::vector<bullet> bullets;
    sf::Color background_color;
    sf::Clock shoot_clock;

public:

    scene() {
        platforms.push_back(platform(128, {400, 450}));
        platforms.push_back(platform(128, {550, 400}));
        platforms.push_back(platform(96, {700, 300}));
        enemies.push_back(enemy({640, 370}));
        shoot_clock.restart();
    }

    void animate(float delta_time) {

        player.behavior(delta_time, platforms);
        if (shoot_clock.getElapsedTime().asSeconds() >= 2) {
            for (enemy& e : enemies) e.shoot(bullets);
            shoot_clock.restart();
        }
        for (bullet& b : bullets) b.behavior(delta_time, player);

        if (not player.is_alive()) {
            std::cout << "GAME OVER" << std::endl;
            exit(0);
        }
    }

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override {
        for (const bullet& b : bullets) target.draw(b);
        for (const platform& p : platforms) target.draw(p);
        for (const enemy& e : enemies) target.draw(e);
        target.draw(player);
    }

    const sf::Color& get_background_color() const {
        return background_color;
    }

    void set_background_color(sf::Color color) {
        if (color.a != 255) throw std::invalid_argument("Background color must be filly opaque");
        this->background_color = color;
    }

    void set_player_position(float x, float y) {
        player.setPosition({x, y});
    }
};

#endif //MOUSE_GAME_SCENE
