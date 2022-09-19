#pragma once

#include <libs_init.hpp>
#include <game.hpp>

const  glm::fvec3 background_color(0.2f, 0.3f, 0.3f);

void load_viewport(Game game);

void perspective_init(Game game);

void draw_context();

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();