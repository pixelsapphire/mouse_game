#ifndef MOUSE_GAME_ANIMATABLE
#define MOUSE_GAME_ANIMATABLE

#include <SFML/Graphics.hpp>

namespace mg {

    class animatable {

    public:

        virtual void animate(float delta_time) = 0;
    };
}

#endif //MOUSE_GAME_ANIMATABLE
