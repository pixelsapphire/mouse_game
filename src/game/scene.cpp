#include <entities/enemy.hpp>
#include <game/game_context.hpp>
#include <game/scene.hpp>
#include <world/moving_platform.hpp>

namespace mg {

    scene::scene(mouse* mouse) {
        player = mouse;
        background.setSize({1280, 768});
        background.setFillColor(sf::Color::White);
        hint_clock.restart();
    }

    void scene::update(float delta_time, game_context& context) {

        context.move_player(delta_time);

        std::erase_if(objects, [&](sf::Drawable* i) {
            const auto c = dynamic_cast<character*>(i);
            if (c != nullptr) return not c->is_alive();
            return false;
        });

//        if (shoot_clock.getElapsedTime().asSeconds() >= 2) {
        for (sf::Drawable* object : objects) {
            const auto e = dynamic_cast<enemy*>(object);
            if (e != nullptr) e->shoot(objects);
        }
//        }
        for (sf::Drawable* object : objects) {
            const auto b = dynamic_cast<bullet*>(object);
            const auto i = dynamic_cast<item*>(object);
            const auto m = dynamic_cast<moving_platform*>(object);
            const auto p = dynamic_cast<portal*>(object);
            if (b != nullptr or i != nullptr or m != nullptr or p != nullptr)
                dynamic_cast<animatable*>(object)->animate(delta_time);
        }
        for (hint& hint : hints) hint.animate(delta_time);

        if (player->getPosition().y > 768) player->oof();
        if (player->getGlobalBounds().findIntersection(exit.getGlobalBounds()).has_value()) {
            player->enter_portal(exit);
            context.finish_level();
        }

        if (not player->is_alive()) ded = true;
    }

    void scene::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
        for (const sf::Drawable* o : objects) target.draw(*o);
        target.draw(*player);
        for (const sf::Text& hint : hints) target.draw(hint);
    }

    void scene::add_platform(float width, const sf::Vector2f& position) {
        objects.push_back(new platform(width, position, get_platform_color()));
    }

    void scene::add_platform(const sf::Vector2f& size, const sf::Vector2f& position) {
        objects.push_back(new platform(size, position, get_platform_color()));
    }

    void scene::add_hint(const std::string& text, const sf::Vector2f& position) {
        hints.emplace_back(text, position);
    }

    std::list<sf::Drawable*>& scene::get_objects() {
        return objects;
    }

    void scene::set_background(const sf::Texture& texture) {
        background.setTexture(&texture);
    }

    sf::RectangleShape& scene::get_background() {
        return background;
    }

    const sf::Color& scene::get_platform_color() const {
        return platform_color;
    }

    void scene::add_object(sf::Drawable* object) {
        objects.push_back(object);
    }

    void scene::set_platform_color(const sf::Color& color) {
        scene::platform_color = color;
    }

    void scene::setup_portal(const sf::Vector2f& position, const sf::Color& color1, const sf::Color& color2) {
        exit = {position, color1, color2};
        objects.push_back(&exit);
    }

    bool scene::is_ded() const {
        return ded;
    }
}
