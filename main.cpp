#include <game/game_context.hpp>
#include <scenes/initial_scene.hpp>
#include <scenes/second_scene.hpp>
#include <assets.hpp>

int main() {

    mg::textures.load();
    mg::fonts::load();
    mg::sounds.load();
    mg::game_context context;

    mg::initial_scene level_1_scene(context.get_player());
    context.get_player().set_scene(level_1_scene);

    context.set_scene(level_1_scene);
    context.start_game();

    return 0;
}
