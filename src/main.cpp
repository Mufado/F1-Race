#include <game_init.hpp>

int main()
{
    /* Comments written to explain less intuitive functions and line codes */

    Game main_game;

    //Load setting creating windows
    load_window_setting(&main_game);
    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default, main_game.window_settings);
    main_game.window = &window;

    //Initial configurations
    project_init(&main_game);

    //Render loop
    while (main_game.window->isOpen())
    {
        //Look for events...
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

        //Configure the projection perspective
        perspective_init(&main_game);

        //Configure and set the camera
        load_camera(&main_game.camera);

        //Render whatever we want in the context
        draw_context(&main_game);

        main_game.window->display();
    }

    return 0;
}
