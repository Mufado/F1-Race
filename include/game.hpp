#pragma once

#include <game_init.hpp>

#include <controls.hpp>
#include <context_draw.hpp>
#include <camera.hpp>
#include <object.hpp>

typedef struct 
{
    sf::Window *window;
    Camera camera;
} Game;

void project_init(Game);