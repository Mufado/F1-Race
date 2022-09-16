#pragma once

#include <SFML/Window/Window.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/OpenGL.hpp>

static bool fullscreen = false;

void keyboard_handler(sf::Event, sf::Window *);