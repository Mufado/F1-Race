#include <controls.hpp>

void debug_controller(Game *game)
{
    game->debug_mode = !game->debug_mode;

    if(!game->debug_mode)
    {
        start_camera(&game->camera);
    }
}

void fullscreen_controller(Game *game)
{
    game->fullscreen = !game->fullscreen;

    if (game->fullscreen)
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Fullscreen, game->window_settings);
    else
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default, game->window_settings);
    
    glEnable(GL_DEPTH_TEST);
}

void axis_size_controller(Game *game)
{
    game->degub_tools = !game->degub_tools;
}

void camera_movement(Game *game)
{
    if(!game->debug_mode)
    {
        game->camera.eye.x = game->main_car.global_position.x;
    }
    else
    {
        game->camera.at  = glm::fvec3(
            (game->camera.eye.x), 
            (game->camera.eye.y) - CAM_VIEW.x, 
            (game->camera.eye.z) - CAM_VIEW.y
        );
    }
}

void movement_handler(Game *game)
{
    
}

void keyboard_handler(sf::Event event, Game *game)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Escape:
            game->window->close();
            break;
        case sf::Keyboard::F11:
            fullscreen_controller(game);
            break;
        case sf::Keyboard::B:
            debug_controller(game);
    }

    if(game->debug_mode)
    {
        game->background_color = DEBUG_COLOR;
        switch (event.key.code)
        {
            case sf::Keyboard::Up:
                game->camera.eye.y++;
                break;
            case sf::Keyboard::Down:
                game->camera.eye.y--;
                break;
            case sf::Keyboard::Right:
                game->camera.eye.x++;
                break;
            case sf::Keyboard::Left:
                game->camera.eye.x--;
                break;
            case sf::Keyboard::LShift:
            case sf::Keyboard::RShift:
                game->camera.eye.z--;  
                break;
            case sf::Keyboard::LControl:
            case sf::Keyboard::RControl:
                game->camera.eye.z++;
                break;
            case sf::Keyboard::X:
                axis_size_controller(game);
                break;
        }   
    }
    else
    {
        game->background_color = DEFAULT_COLOR;
        start_camera(&game->camera);
    }
}
