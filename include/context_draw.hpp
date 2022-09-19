#pragma once

#include <libs_init.hpp>
#include <game.hpp>

static sf::Vector2u window_size;
const  glm::fvec3 background_color(0.2f, 0.3f, 0.3f);

void load_buffers();

void perspective_init(Game game);

void draw_context();

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();