#pragma once

#include <game.hpp>

#define TERRAIN_SIZE  100.0f
#define HIGHWAY_WIDTH   3.0f
#define SIGTH_WIDTH     2.0f
#define SIGHT_SIZE      0.3f

void load_viewport(Game *);

void perspective_init(Game *);

void draw_context(Game *);

void draw_debug_context(Game *);

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();