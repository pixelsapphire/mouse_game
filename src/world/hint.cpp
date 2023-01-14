#include <assets.hpp>
#include <world/hint.hpp>

namespace mg {

    hint::hint(const std::string& text, const sf::Vector2f& position) {
        setFont(fonts::yoster);
        setString(text);
        setPosition(position);
        setCharacterSize(24);
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::Transparent);
        setOutlineThickness(2);
    }

    void hint::animate(float delta_time) {
        opaqueness += delta_time;
        if (opaqueness > 1) opaqueness = 1;
        setFillColor(sf::Color(255, 255, 255, uint8_t(opaqueness * 255)));
        setOutlineColor(sf::Color(0, 0, 0, uint8_t(opaqueness * 255)));
    }
}