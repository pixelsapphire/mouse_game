#include <SFML/Graphics.hpp>
#include <assets.hpp>
#include <world/portal.hpp>

namespace mg {

    portal::portal(const sf::Vector2f& position, const sf::Color& color1, const sf::Color& color2)
            : sf::RectangleShape({64, 64}), initial_color(color1),
              color_diff(int16_t(color2.r) - color1.r, int16_t(color2.g) - color1.g, int16_t(color2.b) - color1.b) {
        setPosition(position);
        setTexture(&textures["env.portal"]);
    }

    void portal::animate(float delta_time) {
        fade_progress += delta_time * 200;
        const float saw = float(std::abs(uint16_t(fade_progress) % 512 - 255)) / 255;
        setFillColor(sf::Color(initial_color.r + color_diff.x * saw,
                               initial_color.g + color_diff.y * saw,
                               initial_color.b + color_diff.z * saw));
    }
}
