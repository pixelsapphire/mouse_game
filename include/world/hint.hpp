#ifndef MOUSE_GAME_HINT
#define MOUSE_GAME_HINT

#include <SFML/Graphics.hpp>
#include <entities/animatable.hpp>

namespace mg {

    class hint : public sf::Text, public animatable {

        float opaqueness = 0;

    public:

        hint(const std::string& text, const sf::Vector2f& position);

        void animate(float delta_time) override;
    };
}

#endif //MOUSE_GAME_HINT
