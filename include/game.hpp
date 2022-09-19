#pragma once

#include <libs_init.hpp>
#include <camera.hpp>

#define DEFAULT_COLOR glm::fvec4(0.2f, 0.5f, 0.3f, 1.0f)
#define DEBUG_COLOR glm::fvec4(0.3f, 0.3f, 0.3f, 1.0f)

#define DEFAULT_AXIS_SIZE 40.0f
#define REDUCED_AXIS_SIZE 10.0f

typedef struct 
{
    Camera camera;

    sf::Window *window;
    sf::Vector2u window_size;

    glm::fvec4 background_color = DEFAULT_COLOR;

    boolean fullscreen = false;
    boolean debug_mode = false;
    boolean reduced_axis = false;

    float axis_size = DEFAULT_AXIS_SIZE;
} Game;

void project_init(Game *);