#include <SFML/Graphics.hpp>

#include <entities/animatable.hpp>
#include <entities/character.hpp>

namespace mg {

    void character::animate(float delta_time) {}

    void character::damage(int damage) {
        clock.restart();
        hp -= damage;
        setFillColor(sf::Color::Red);
    }

    int character::get_hp() const {
        return hp;
    }

    void character::update_damage_cooldown() {
        if (clock.getElapsedTime().asSeconds() > 0.5) setFillColor(sf::Color::White);
    }

    bool character::is_alive() const {
        return hp > 0;
    }

}
