#pragma once

#include <SFML/Window/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/ext.hpp>

static sf::Vector2u window_size;
const  glm::fvec3 background_color(0.2f, 0.3f, 0.3f);

void project_init();

void load_buffers();

void perspective_init(sf::Window *);

void draw_context();

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();