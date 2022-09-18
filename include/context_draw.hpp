#pragma once

#include <SFML/Window/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <glm/ext.hpp>

void project_init();

void perspective_init(sf::Window *);

void draw_context();

void draw_sky();

void draw_terrain();

void draw_highway();

void draw_opponents();

void draw_car();