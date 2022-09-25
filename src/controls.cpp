#include <controls.hpp>

void debug_controller(Game *game)
{
    game->debug_mode = !game->debug_mode;

    //Some cool stuff's coming ... ;)
}

void fullscreen_controller(Game *game)
{
    game->fullscreen = !game->fullscreen;

    if (game->fullscreen)
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Fullscreen, game->window_settings);
    else
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default, game->window_settings);
}

void axis_size_controller(Game *game)
{
    game->cartesian = !game->cartesian;
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
        case sf::Keyboard::W:

            break;
        case sf::Keyboard::A:

            break;
        case sf::Keyboard::S:

            break;
        case sf::Keyboard::D:

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
        game->background_color = DEFAULT_COLOR;
}