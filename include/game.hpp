#pragma once

#include <libs_init.hpp>
#include <camera.hpp>

typedef struct 
{
    sf::Window *window;
    Camera camera;

    sf::Vector2u window_size;

    bool debug_mode = false;
} Game;

void project_init(Game);