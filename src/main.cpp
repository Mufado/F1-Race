#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <controls.hpp>
#include <context_draw.hpp>
#include <camera.hpp>
#include <object.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
    
    float red = 0.2f;
    float green = 0.3f;
    float blue = 0.3f;

    project_init();

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

        glClearColor(red, green, blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        perspective_init(&window);

        draw_context();

        window.display();
    }

    return 0;
}