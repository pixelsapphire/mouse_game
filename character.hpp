#ifndef MOUSE_GAME_CHARACTER
#define MOUSE_GAME_CHARACTER

#include <SFML/Graphics.hpp>

class character : public sf::RectangleShape {

protected:

    sf::Vector2f velocity = {0, 0}; // px / s
    int hp = 0;

public:

    void damage(int damage) {
        hp -= damage;
        setFillColor(sf::Color::Red);
    }

    bool is_alive() {
        return hp > 0;
    }
};

#endif //MOUSE_GAME_CHARACTER
