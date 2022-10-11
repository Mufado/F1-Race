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
        .local_position  = DEFAULT_LOCAL_POS
    };

    //Controls physics of world movements
    float velocity = 0.0f;
    float acceleration = 0.0f;
    float motion = 0.0f;

    boolean fullscreen   = false;
    boolean debug_mode   = false;
    boolean degub_tools  = true;
} Game;

void physics_handler(Game *);

void load_window_setting(Game *);

void project_init(Game *);