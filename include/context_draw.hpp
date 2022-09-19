#pragma once

#include <libs_init.hpp>
#include <game.hpp>

void load_viewport(Game *game);

void perspective_init(Game *game);

void draw_context();

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();