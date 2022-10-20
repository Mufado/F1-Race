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
    int32_t sky_gradiant = 0;
    int32_t day_time = 0;

    //Load setting creating windows
    load_window_setting(&main_game);
    sf::Window window(sf::VideoMode::getDesktopMode(), "F1_Race", sf::Style::Default, main_game.window_settings);
    main_game.window = &window;

    //Initial configurations
    project_init(&main_game);

    //Render loop
    while (main_game.window->isOpen())
    {
        // This srand() is for the pseudo-random generator
        std::srand(std::time(NULL)); // It's in the while statement to reseed the srand() every time !

        sf::Time response_time = main_game.response_clock.getElapsedTime();
        sf::Time game_time     = main_game.game_clock.getElapsedTime();

        if(response_time.asSeconds() > 0.5f && main_game.velocity > 0.0f)
        {
            if(main_game.velocity - CAR_SLOWDOWN > 0)
                main_game.velocity -= CAR_SLOWDOWN;
            else    
                main_game.velocity = 0;

            main_game.response_clock.restart();
        }

        if(game_time.asSeconds() > 1.0f && !main_game.debug_mode && sky_gradiant < SKY_GRADIENT)
        {
            if(day_time > 2)
                day_time = 0;

            switch (day_time)
            {
                case 0: //Day -> Afternoon
                    main_game.background_color.x += 4.20f;
                    main_game.background_color.y += 0.30f;
                    main_game.background_color.z -= 2.37f;
                    break;
                case 1: //Afternoon -> Night
                    main_game.background_color.x -= 6.02f;
                    main_game.background_color.y -= 4.07f;
                    main_game.background_color.z -= 2.42f;
                    break;
                case 2: //Night -> Day
                    main_game.background_color.x += 1.82f;
                    main_game.background_color.y += 3.77f;
                    main_game.background_color.z += 4.80f;
                    break;
            }

            main_game.memorized_color = main_game.background_color;            
            main_game.game_clock.restart();
            sky_gradiant++;
        }
        else if(sky_gradiant == SKY_GRADIENT)
        {
            day_time++;
            sky_gradiant = 0;
        }

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
