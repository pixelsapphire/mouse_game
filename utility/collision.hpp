#ifndef MOUSE_GAME_COLLISION
#define MOUSE_GAME_COLLISION

#include <SFML/Graphics.hpp>

namespace mg {

    enum collision_axis {
        x, y, both, none
    };

    collision_axis aabb_collision(const sf::RectangleShape& moving, const sf::Vector2f& offset,
                                  const sf::RectangleShape& stationary) {
        const sf::FloatRect a = moving.getGlobalBounds(), b = stationary.getGlobalBounds();
        bool horizontal = a.left + offset.x < b.left + b.width and a.left + a.width + offset.x > b.left and
                          not(a.top >= b.top + b.height or a.top + a.height <= b.top);
        bool vertical = a.top + offset.y < b.top + b.height and a.top + a.height + offset.y > b.top and
                        not(a.left >= b.left + b.width or a.left + a.width <= b.left);
        if (horizontal && vertical) return collision_axis::both;
        if (horizontal) return collision_axis::x;
        if (vertical) return collision_axis::y;
        return collision_axis::none;
    }
}

#endif //MOUSE_GAME_COLLISION
