#ifndef MOUSE_GAME_PORTAL
#define MOUSE_GAME_PORTAL

#include <SFML/Graphics.hpp>
#include <assets.hpp>
#include <entities/animatable.hpp>

namespace mg {

    class portal : public sf::RectangleShape, public animatable {
        sf::Color initial_color;
        sf::Vector3<int16_t> color_diff;
        float fade_progress = 0;

    public:

        portal() = default;

        portal(const sf::Vector2f& position, const sf::Color& color1, const sf::Color& color2);

        void animate(float delta_time) override;
    };
}

#endif //MOUSE_GAME_PORTAL
