#pragma once

#include <camera.hpp>
#include <object.hpp>

typedef struct 
{
    //Measuring timing to help in game physics
    sf::Clock clock;

    Camera camera;

    sf::Window *window;
    sf::Vector2u window_size;
    sf::ContextSettings window_settings;

    glm::fvec4 background_color = DEFAULT_COLOR;

    // Scenario Object's
    Object main_car = 
    {
        .global_position = DEFAULT_CAR_POS,
        // .local_position  = DEFAULT_LOCAL_POS
    };

    //Controls physics of world movements
    glm::fvec3 terrain_cord = glm::fvec3(0.0f, 0.0f, 0.0f);

    float velocity = 0.0;
    float aceleration = 0.3;

    //Camera angle
    double rotate_angule = 0.0;

    boolean fullscreen   = false;
    boolean debug_mode   = false;
    boolean degub_tools  = false;

} Game;

void physics_handler(Game *);

void load_window_setting(Game *);

void project_init(Game *);