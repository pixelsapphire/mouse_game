#ifndef MOUSE_GAME_COLLISION
#define MOUSE_GAME_COLLISION

#include <SFML/Graphics.hpp>

namespace mg {

    enum collision_axis {
        x, y, both, none
    };

    collision_axis aabb_collision(const sf::RectangleShape& moving, const sf::Vector2f& offset,
                                  const sf::RectangleShape& stationary);
}

#endif //MOUSE_GAME_COLLISION
