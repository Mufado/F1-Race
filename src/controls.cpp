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
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Fullscreen);
    else
        game->window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
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
                
                break;
            case sf::Keyboard::Down:
                
                break;
            case sf::Keyboard::Left:

                break;
            case sf::Keyboard::Right:

                break;
            case sf::Keyboard::LShift:
            case sf::Keyboard::RShift:

                break;
            case sf::Keyboard::LControl:
            case sf::Keyboard::RControl:

                break;
        }   
    }
    else
        game->background_color = DEFAULT_COLOR;
}