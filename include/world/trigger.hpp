#ifndef MOUSE_GAME_TRIGGER
#define MOUSE_GAME_TRIGGER

#include <utility>
#include <SFML/Graphics.hpp>
#include <assets.hpp>

namespace mg {

    enum trigger_type {
        lever, keyhole
    };

    class trigger : public sf::RectangleShape {

        trigger_type type;
        std::function<bool()> on_activate;
        bool activated = false;

    public:

        trigger(trigger_type type, sf::Vector2f position, std::function<bool()> on_activate);

        void switch_on() ;
    };
}

#endif //MOUSE_GAME_TRIGGER
