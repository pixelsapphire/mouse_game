#ifndef MOUSE_GAME_ASSETS
#define MOUSE_GAME_ASSETS

#include <SFML/Graphics.hpp>

namespace mg::textures {

    sf::Texture item_cheese, item_key;

    void load() {
        item_cheese.loadFromFile("../assets/cheese.png");
        item_key.loadFromFile("../assets/key.png");
    }
}

#endif //MOUSE_GAME_ASSETS
