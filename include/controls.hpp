#pragma once

#include <libs_init.hpp>
#include <game.hpp>

static bool fullscreen = false;

void fullscreen_controller(sf::Window *);

void keyboard_handler(sf::Event, Game);