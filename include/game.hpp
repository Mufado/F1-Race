#pragma once

#include <camera.hpp>
#include <object.hpp>

typedef struct 
{
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

    boolean fullscreen   = false;
    boolean debug_mode   = false;
    boolean degub_tools  = true;
} Game;

void load_window_setting(Game *);

void project_init(Game *);