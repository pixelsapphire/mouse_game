#include <SFML/Graphics.hpp>
#include <entities/animatable.hpp>
#include <world/moving_platform.hpp>
#include <world/platform.hpp>

namespace mg {

    moving_platform::moving_platform(sf::Vector2f size, sf::Vector2f position, const sf::Color& color)
            : platform(size, position, color), target(position) {}

    moving_platform::moving_platform(float width, sf::Vector2f position, const sf::Color& color)
            : moving_platform({width, 24}, position, color) {}

    void moving_platform::set_point(sf::Vector2f point) {
        target = point;
    }

    void moving_platform::animate(float delta_time) {
        const auto pos = getPosition();
        if (target != pos) {
            const sf::Vector2f direction = (target - pos) / std::hypot(target.x - pos.x, target.y - pos.y);
            const sf::Vector2f offset = direction * velocity * delta_time;
            if ((target - pos).length() >= offset.length()) move(offset);
            else setPosition(target);
        }
    }
}