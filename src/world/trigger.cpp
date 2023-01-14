#include <utility>
#include <SFML/Graphics.hpp>
#include <world/trigger.hpp>

namespace mg {

    trigger::trigger(trigger_type type, sf::Vector2f position, std::function<bool()> on_activate)
            : type(type), on_activate(std::move(on_activate)) {

        if (type == trigger_type::lever) {
            setTexture(&textures["trigger.lever.off"]);
            setSize({48, 48});
        } else if (type == trigger_type::keyhole) {
            setTexture(&textures["trigger.keyhole"]);
            setSize({24, 24});
        } else {
            setFillColor(sf::Color(240, 0, 64));
            setSize({24, 24});
        }

        setPosition(position);
    }

    void trigger::switch_on() {
        if (not activated) {
            const bool success = on_activate();
            if (success) {
                activated = true;
                if (type == trigger_type::lever) setTexture(&textures["trigger.lever.on"]);
                else if (type == trigger_type::keyhole) setFillColor(sf::Color::Transparent);
                else setFillColor(sf::Color(0, 196, 64));
            }
        }
    }

}

