#include <assets.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace mg {

    void textures_bundle::load() {
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

    textures_bundle textures;

    sf::Texture& textures_bundle::operator[](const std::string& name) {
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

    void fonts::load() {
        yoster.loadFromFile("assets/yoster.ttf");
    }

    sf::Font fonts::yoster;

    void sounds_bundle::load() {
        buffer_game_over.loadFromFile("assets/fail.wav");
        sound_game_over.setBuffer(buffer_game_over);
    }

    sf::Sound& sounds_bundle::operator[](const std::string& name) {
        if (name == "sfx.game_over") return sound_game_over;
        throw std::runtime_error("Unknown asset name: " + name);
    }

    sounds_bundle sounds;
}
