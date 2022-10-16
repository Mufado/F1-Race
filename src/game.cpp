#include <game.hpp>

void physics_handler(Game *game)
{
    
}

void load_window_setting(Game *game)
{
    game->window_settings.depthBits         = 24;
    game->window_settings.stencilBits       = 8;
    game->window_settings.antialiasingLevel = 4;
    game->window_settings.majorVersion      = 3;
    game->window_settings.minorVersion      = 0;
    game->window_settings.sRgbCapable       = 0;
}

void load_objects(Game *game)
{
    game->main_car = load_obj_from_file(CAR_FILE_NAME);
    game->main_car.global_position = DEFAULT_CAR_POS;
}

void project_init(Game *game)
{
    game->window->setFramerateLimit(60);
    game->window->setKeyRepeatEnabled(true);

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    load_objects(game);

    start_camera(&game->camera);
}
