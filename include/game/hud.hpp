#ifndef MOUSE_GAME_HUD
#define MOUSE_GAME_HUD

#include <SFML/Graphics.hpp>
#include <entities/mouse.hpp>

namespace mg {

    class hud : public sf::Drawable {

        mouse& player;
        sf::RectangleShape cheese{{32, 32}}, heart{{32, 32}}, key{{32, 32}};
        sf::Text cheese_counter, keys_counter, gameover_text;

    public:

        explicit hud(mouse& player);

        void move(const sf::Vector2f& offset);

        void update();

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    };
}

#endif //MOUSE_GAME_HUD
