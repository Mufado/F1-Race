#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "My window", sf::Style::Default);

    window.setSize(sf::Vector2u(800, 600));
    
    // run the program as long as the window is open
    while (window.isOpen())
    {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    return 0;
}