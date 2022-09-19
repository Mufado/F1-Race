#pragma once

#include <libs_init.hpp>
#include <camera.hpp>

#define DEFAULT_COLOR glm::fvec4(0.2f, 0.3f, 0.3f, 1.0f)

typedef struct 
{
    sf::Window *window;
    Camera camera;

    sf::Vector2u window_size;
    glm::fvec4 background_color = DEFAULT_COLOR;

    bool debug_mode = false;
} Game;

void project_init(Game);