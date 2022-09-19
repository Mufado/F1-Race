#include <game_init.hpp>

int main()
{
    Game main_game;

    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default);
    main_game.window = &window;

    project_init(&main_game);

    while (main_game.window->isOpen())
    {
        sf::Event event;
        while (main_game.window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    main_game.window->close();
                    break;  
                case sf::Event::KeyPressed:
                    keyboard_handler(event, &main_game);
                    break;
            }
        }

        perspective_init(&main_game);

        load_camera(&main_game.camera);

        draw_context(&main_game);

        main_game.window->display();
    }

    return 0;
}