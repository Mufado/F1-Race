#pragma once

#include <game.hpp>

void load_viewport(Game *);

void perspective_init(Game *);

void draw_context(Game *);

void draw_debug_context(Game *);

void draw_ground(Game *);

void draw_terrain();

void draw_highway();

void draw_strips();

void draw_opponents(Game *);

void draw_car(Object);
