#pragma once

#include <SFML/OpenGL.hpp>
#include <glm/ext.hpp>

typedef struct
{
   glm::fvec3 eye; 
   glm::fvec3 at;
   glm::fvec3 up;
} Camera;

void start_camera(Camera);

void load_camera(Camera);