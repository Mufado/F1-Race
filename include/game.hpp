#pragma once

#include <libs_init.hpp>
#include <camera.hpp>

#define DEFAULT_COLOR glm::fvec4(0.2f, 0.3f, 0.3f, 1.0f)
#define DEBUG_COLOR glm::fvec4(0.2f, 0.5f, 0.3f, 1.0f)

typedef struct 
{
    Camera camera;

    sf::Window *window;
    sf::Vector2u window_size;

    glm::fvec4 background_color = DEFAULT_COLOR;

    boolean fullscreen;
    boolean debug_mode;
} Game;

void project_init(Game *);