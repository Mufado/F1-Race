#pragma once

#include <game.hpp>

void debug_controller(Game *);

void fullscreen_controller(Game *);

void axis_size_controller(Game *);

void move_player(Game *, sf::Keyboard::Key);

void keyboard_handler(sf::Event, Game *);
