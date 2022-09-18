#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <controls.hpp>
#include <context_draw.hpp>
#include <camera.hpp>
#include <object.hpp>

int main()
{
    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
    sf::Vector2u window_size = window.getSize();

    project_init();

    Camera main_camera;
    start_camera(main_camera);

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

        glViewport(0, 0, window_size.x, window_size.y);

        load_buffers();

        perspective_init(&window);

        load_camera(main_camera);

        draw_context();

        window.display();
    }

    return 0;
}