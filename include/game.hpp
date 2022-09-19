#pragma once

#include <libs_init.hpp>
#include <camera.hpp>

typedef struct 
{
    sf::Window *window;
    Camera camera;
} Game;

void project_init(Game);