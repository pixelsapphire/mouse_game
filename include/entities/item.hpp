#ifndef MOUSE_GAME_ITEM
#define MOUSE_GAME_ITEM

#include <list>
#include <SFML/Graphics.hpp>
#include <assets.hpp>
#include <entities/character.hpp>
#include <definitions.hpp>
#include <utility/collision.hpp>
#include <world/platform.hpp>

namespace mg {

    enum item_type {
        key, cheese, heart
    };

    class item : public character {

        item_type type;
        const std::list<sf::Drawable*>& objects;
        bool gravity_affected = false;

    public:

        item(item_type type, sf::Vector2f position, const std::list<sf::Drawable*>& objects, bool has_gravity = false);

        void set_gravity_affected(bool gravity);

        item_type get_type() const;

        void animate(float delta_time) override;
    };
}

#endif //MOUSE_GAME_ITEM
