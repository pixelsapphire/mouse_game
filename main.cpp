#include "game/game_context.hpp"
#include "scenes/initial_scene.hpp"

int main() {

    mg::game_context context;

    mg::initial_scene level_1_scene;
    level_1_scene.set_player_position(450, 350);

    context.set_scene(level_1_scene);
    context.start_game();

    return 0;
}
