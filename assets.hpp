#ifndef MOUSE_GAME_ASSETS
#define MOUSE_GAME_ASSETS

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace mg {

    class textures_bundle {

        sf::Texture background, bg_placeholder,
                item_cheese, item_key, item_heart,
                trigger_lever_off, trigger_lever_on, trigger_keyhole,
                entity_mouse, entity_mouse_flipped, entity_cat_the_enemy,
                env_portal;

    public:

        void load() {
            item_cheese.loadFromFile("assets/cheese.png");
            item_key.loadFromFile("assets/key.png");
            trigger_lever_off.loadFromFile("assets/lever_off.png");
            trigger_lever_on.loadFromFile("assets/lever_on.png");
            trigger_keyhole.loadFromFile("assets/keyhole.png");
            background.loadFromFile("assets/bg.png");
            bg_placeholder.loadFromFile("assets/bg_placeholder.png");
            item_heart.loadFromFile("assets/heart.png");
            entity_mouse.loadFromFile("assets/mouse_r.png");
            entity_mouse_flipped.loadFromFile("assets/mouse_l.png");
            entity_cat_the_enemy.loadFromFile("assets/nyan.png");
            env_portal.loadFromFile("assets/portal.png");
        }

        sf::Texture& operator[](const std::string& name) {
            if (name == "background") return background;
            if (name == "item.cheese") return item_cheese;
            if (name == "item.key") return item_key;
            if (name == "item.heart") return item_heart;
            if (name == "trigger.lever.oof") return trigger_lever_off;
            if (name == "trigger.lever.on") return trigger_lever_on;
            if (name == "trigger.keyhole") return trigger_keyhole;
            if (name == "entity.mouse") return entity_mouse;
            if (name == "entity.mouse_flipped") return entity_mouse_flipped;
            if (name == "entity.cat_the_enemy") return entity_cat_the_enemy;
            if (name == "env.portal") return env_portal;
            throw std::runtime_error("Unknown asset name: " + name);
        }
    };

    textures_bundle textures;

    namespace fonts {

        sf::Font yoster;

        void load() {
            yoster.loadFromFile("assets/yoster.ttf");
        }
    }

    class sounds_bundle {

        sf::SoundBuffer buffer_game_over;
        sf::Sound sound_game_over;

    public:

        void load() {
            buffer_game_over.loadFromFile("assets/fail.wav");
            sound_game_over.setBuffer(buffer_game_over);
        }

        sf::Sound& operator[](const std::string& name) {
            if (name == "sfx.game_over") return sound_game_over;
            throw std::runtime_error("Unknown asset name: " + name);
        }
    };

    sounds_bundle sounds;
}

#endif //MOUSE_GAME_ASSETS
