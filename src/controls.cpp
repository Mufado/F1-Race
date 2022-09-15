#include <controls.hpp>

void keyboard_handler(sf::Event event, sf::Window *window)
{
    switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                window->close();
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