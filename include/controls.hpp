#pragma once

#include <game.hpp>

void debug_controller(Game *);

void fullscreen_controller(Game *);

void axis_size_controller(Game *);

void movement_handler(Game *, sf::Keyboard::Key);

void window_handler(Game *, sf::Keyboard::Key);

void debug_handler(Game *, sf::Keyboard::Key);

void keyboard_handler(Game *, sf::Keyboard::Key);

void camera_movement(Game *);
