#include <game.hpp>

void load_window_setting(Game *game)
{
    game->window_settings.depthBits         = 24;
    game->window_settings.stencilBits       =  8;
    game->window_settings.antialiasingLevel =  4;
    game->window_settings.majorVersion      =  3;
    game->window_settings.minorVersion      =  0;
    game->window_settings.sRgbCapable       =  0;
}

void project_init(Game *game)
{
    game->window->setFramerateLimit(60);
    game->window->setKeyRepeatEnabled(true);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    start_camera(&game->camera);
}