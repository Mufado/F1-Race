#include <controls.hpp>

void fullscreen_controller(sf::Window *window)
{
    if (!fullscreen)
    {
        window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Fullscreen);
        fullscreen = !fullscreen;
    }
    else
    {
        window->create(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
        fullscreen = !fullscreen;
    }
}

void keyboard_handler(sf::Event event, Game game)
{
    switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                game.window->close();
                break;
            case sf::Keyboard::F11:
                fullscreen_controller(game.window);
                break;
            case sf::Keyboard::W:
                
                break;
            case sf::Keyboard::A:
                
                break;
            case sf::Keyboard::S:
                
                break;
            case sf::Keyboard::D:
                
                break;
        }
}