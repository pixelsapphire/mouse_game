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

        void load();

        sf::Texture& operator[](const std::string& name);
    };

    extern textures_bundle textures;

    namespace fonts {

        extern sf::Font yoster;

        void load();
    }

    class sounds_bundle {

        sf::SoundBuffer buffer_game_over;
        sf::Sound sound_game_over;

    public:

        void load();

        sf::Sound& operator[](const std::string& name);
    };

    extern sounds_bundle sounds;
}

#endif //MOUSE_GAME_ASSETS
