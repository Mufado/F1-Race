#pragma once

#include <camera.hpp>

#define DEFAULT_COLOR glm::fvec4(0.53f, 0.81f, 0.92f, 1.0f)
#define DEBUG_COLOR glm::fvec4(0.3f, 0.3f, 0.3f, 1.0f)

typedef struct 
{
    Camera camera;

    sf::Window *window;
    sf::Vector2u window_size;
    sf::ContextSettings window_settings;

    glm::fvec4 background_color = DEFAULT_COLOR;

    boolean fullscreen   = false;
    boolean debug_mode   = false;
    boolean degub_tools    = true;
} Game;

void load_window_setting(Game *);

void project_init(Game *);