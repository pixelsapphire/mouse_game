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
        sf::Clock shoot_clock;

    public:

        explicit scene(mouse* mouse);

        void update(float delta_time, class game_context& context);

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const;

        std::list<sf::Drawable*>& get_objects();

        void set_background(const sf::Texture& texture);

        sf::RectangleShape& get_background();

        const sf::Color& get_platform_color() const;

        void set_platform_color(const sf::Color& color);

        bool is_ded() const;
    };
}

#endif //MOUSE_GAME_SCENE
