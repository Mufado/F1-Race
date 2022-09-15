#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <controls.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Default);
    
    double r, g, b;

    r = g = b = 0.2;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;  
                case sf::Event::KeyPressed:
                    keyboard_handler(event, &window);

            }
        }

		glClear(GL_COLOR_BUFFER_BIT);

        window.display();
    }

    return 0;
}