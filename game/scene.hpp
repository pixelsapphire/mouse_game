#ifndef MOUSE_GAME_SCENE
#define MOUSE_GAME_SCENE

#include <list>
#include <SFML/Graphics.hpp>

namespace mg {

    class scene : public sf::Drawable {

    protected:

        std::list<sf::Drawable*> objects;
        sf::RectangleShape background;
        sf::Color platform_color;
        bool ded = false;

        class mouse* player;

    public:

        scene(mouse* mouse) {
            player = mouse;
            background.setSize({1280, 768});
            background.setFillColor(sf::Color::White);
        }

        virtual void update(float delta_time, class game_context& context) = 0;

        [[nodiscard]] virtual const sf::Color& get_background_color() const = 0;

        std::list<sf::Drawable*>& get_objects() {
            return objects;
        }

        void set_background(const sf::Texture& texture) {
            background.setTexture(&texture);
        }

        sf::RectangleShape& get_background() {
            return background;
        }

        const sf::Color& get_platform_color() const {
            return platform_color;
        }

        void set_platform_color(const sf::Color& color) {
            scene::platform_color = color;
        }

        bool is_ded() const {
            return ded;
        }
    };
}

#endif //MOUSE_GAME_SCENE
