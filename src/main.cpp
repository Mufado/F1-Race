#include <game.hpp>

int main()
{
    Game main_game;

    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
    main_game.window = &window;

    project_init(main_game);

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

        perspective_init(&window);

        //load_camera(main_camera);

        draw_context();

        window.display();
    }

    return 0;
}