#include <game_init.hpp>

/*
 * Basic remake of F1 Race game (1984) by a computer graphics begginer. Made in classic Open GL.
 * Program behavior:
 * - Draw a highway and objects (opponents and other stuf)
 * - Draw the main car and set camera's eye always above it
 * - Controls response makes entire world move around the main car to leave a movement feeling for the player
*/

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
        sf::Time time = main_game.clock.getElapsedTime();

        if(time.asSeconds() > 0.5f && main_game.velocity > 0.0f)
        {
            if(main_game.velocity - CAR_SLOWDOWN > 0)
                main_game.velocity -= CAR_SLOWDOWN;
            else    
                main_game.velocity = 0;

            main_game.clock.restart();
        }

        std::cout << main_game.velocity << std::endl;
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
                    keyboard_handler(&main_game, event.key.code);
                    break;
            }
        }

        //Configure the projection perspective
        perspective_init(&main_game);

        //Configure the camera position
        camera_movement(&main_game);

        //Set the camera in the world
        load_camera(&main_game.camera);

        //Render whatever we want in the context
        draw_context(&main_game);

        main_game.window->display();
    }

    return 0;
}
