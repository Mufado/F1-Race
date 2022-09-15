#include <controls.hpp>

void keyboard_handler(sf::Event event)
{
    switch(event.key.code)
        {
            case sf::Keyboard::W:
                glClearColor(1.0, 0.0, 0.0, 1.0);
                break;
            case sf::Keyboard::A:
                glClearColor(0.0, 0.1, 0.0, 1.0);
                break;
            case sf::Keyboard::S:
                glClearColor(0.0, 0.0, 1.0, 1.0);
                break;
            case sf::Keyboard::D:
                glClearColor(1.0, 1.0, 1.0, 0.5);
                break;
        }
}