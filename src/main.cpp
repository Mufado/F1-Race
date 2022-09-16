#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <controls.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
    
    float red = 0.2f;
    float green = 0.3f;
    float blue = 0.3f;

    glClearColor(red, green, blue, 1.0f);

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