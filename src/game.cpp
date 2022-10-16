#include <game.hpp>

void load_viewport(Game *game)
{
    game->window_size = game->window->getSize();

    glViewport(0, 0, game->window_size.x, game->window_size.y);

    glClearColor(game->background_color.x, game->background_color.y, game->background_color.z, game->background_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void perspective_init(Game *game)
{
    load_viewport(game);

    float aspect_ratio = float(game->window_size.x) / float(game->window_size.y);
    glm::mat4 projection_mat = glm::perspective(45.0f, aspect_ratio, 0.1f, 300.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection_mat));
}

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
