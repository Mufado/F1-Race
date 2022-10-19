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

    for(int i = 0; i < OPPONENTS_NUMBER; i++)
    {
        Object new_oponent;

        new_oponent.obj_meshe.vertex_list = game->main_car.obj_meshe.vertex_list;
        new_oponent.global_position = DEFAULT_OPPONENT_POS;
        
        if(game->opponents.size() > 0) // Has opponents in the opponents list
            new_oponent.global_position.z += (game->opponents[game->opponents.size() - 1].global_position.z + OPPONENTS_DISTANCE);

        new_oponent.global_position.x = ((std::rand() % 2) == TRUE) ? (OPPONENTS_HIGHWAY_SIDE) : -(OPPONENTS_HIGHWAY_SIDE);
        new_oponent.color = glm::fvec3
        (
            (float) ((std::rand() % 256) / 255.0f),
            (float) ((std::rand() % 256) / 255.0f),
            (float) ((std::rand() % 256) / 255.0f)
        );

        game->opponents.push_back(new_oponent);
    }
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
