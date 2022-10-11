#pragma once

#include <game.hpp>

void debug_controller(Game *);

void fullscreen_controller(Game *);

void axis_size_controller(Game *);

void movement_handler(Game *);

void keyboard_handler(sf::Event, Game *);

void camera_movement(Game *);
