#ifndef MOUSE_GAME_HUD
#define MOUSE_GAME_HUD

#include <SFML/Graphics.hpp>
#include "entities/mouse.hpp"

namespace mg {

    class hud : public sf::Drawable {

        mouse& player;
        sf::RectangleShape cheese{{32, 32}}, heart{{32, 32}}, key{{32, 32}};
        sf::Text cheese_counter, keys_counter, gameover_text;

    public:

        explicit hud(mouse& player) : player(player) {
            heart.setPosition({10, 10});
            heart.setTexture(&textures["item.heart"]);
            cheese.setPosition({10, 50});
            cheese.setTexture(&textures["item.cheese"]);
            key.setPosition({10, 90});
            key.setTexture(&textures["item.key"]);
            cheese_counter.setPosition({50, 50});
            cheese_counter.setFont(fonts::yoster);
            cheese_counter.setCharacterSize(24);
            cheese_counter.setFillColor(sf::Color::White);
            cheese_counter.setOutlineThickness(2);
            cheese_counter.setOutlineColor(sf::Color::Black);
            keys_counter.setPosition({50, 90});
            keys_counter.setFont(fonts::yoster);
            keys_counter.setCharacterSize(24);
            keys_counter.setFillColor(sf::Color::White);
            keys_counter.setOutlineThickness(2);
            keys_counter.setOutlineColor(sf::Color::Black);
            gameover_text.setPosition({640, 384});
            gameover_text.setFont(fonts::yoster);
            gameover_text.setCharacterSize(64);
            gameover_text.setString("Game Over");
            gameover_text.setFillColor(sf::Color::White);
            gameover_text.setOutlineThickness(5);
            gameover_text.setOutlineColor(sf::Color::Black);
            gameover_text.setOrigin(gameover_text.getGlobalBounds().getSize() / 2.0f);
        }

        void move(const sf::Vector2f& offset) {
            heart.move(offset);
            cheese.move(offset);
            cheese_counter.move(offset);
            key.move(offset);
            keys_counter.move(offset);
            gameover_text.move(offset);
        }

        void update() {
            cheese_counter.setString("x" + std::to_string(player.get_inventory().cheese));
            keys_counter.setString("x" + std::to_string(player.get_inventory().key));
        }

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override {
            sf::Transform transform = states.transform;
            for (int i = 0; i < player.get_hp(); i++) {
                target.draw(heart, sf::RenderStates{states.blendMode, transform, states.texture, states.shader});
                transform.translate({36, 0});
            }
            target.draw(cheese, states);
            target.draw(key, states);
            target.draw(cheese_counter, states);
            target.draw(keys_counter, states);
            if (not player.is_alive()) {
                target.draw(gameover_text, states);
            }
        }
    };
}

#endif //MOUSE_GAME_HUD
