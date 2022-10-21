#ifndef MOUSE_GAME_SCENE
#define MOUSE_GAME_SCENE

#include <SFML/Graphics.hpp>

namespace mg {

    struct scene : public sf::Drawable {

        virtual void update(float delta_time) = 0;

        [[nodiscard]] virtual const sf::Color& get_background_color() const = 0;
    };
}

#endif //MOUSE_GAME_SCENE
