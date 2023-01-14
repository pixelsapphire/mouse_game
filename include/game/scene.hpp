#ifndef MOUSE_GAME_SCENE
#define MOUSE_GAME_SCENE

#include <list>
#include <SFML/Graphics.hpp>
#include <world/hint.hpp>
#include <world/portal.hpp>

namespace mg {

    class scene : public sf::Drawable {

    protected:

        std::list<sf::Drawable*> objects;
        std::list<hint> hints;
        sf::RectangleShape background;
        sf::Color platform_color;
        bool ded = false;

        class mouse* player;

        sf::Clock hint_clock;
        portal exit;

        void setup_portal(const sf::Vector2f& position, const sf::Color& color1, const sf::Color& color2);

        void set_background(const sf::Texture& texture);

        void set_platform_color(const sf::Color& color);

        void add_object(sf::Drawable* object);

        void add_platform(float width, const sf::Vector2f& position);

        void add_platform(const sf::Vector2f& size, const sf::Vector2f& position);

        void add_hint(const std::string& text, const sf::Vector2f& position);

    public:

        explicit scene(mouse* mouse);

        virtual void update(float delta_time, class game_context& context);

        void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

        std::list<sf::Drawable*>& get_objects();

        sf::RectangleShape& get_background();

        const sf::Color& get_platform_color() const;

        bool is_ded() const;
    };
}

#endif //MOUSE_GAME_SCENE
