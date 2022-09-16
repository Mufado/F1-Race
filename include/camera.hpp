#pragma once

#include <SFML/OpenGL.hpp>
#include <glm/ext.hpp>

typedef struct
{
   glm::fvec3 position; 
} Camera;

void set_camera_pos(glm::fvec3);