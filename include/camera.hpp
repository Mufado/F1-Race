#pragma once

#include <libs_init.hpp>

typedef struct
{
   glm::fvec3 eye; 
   glm::fvec3 at;
   glm::fvec3 up;
} Camera;

void start_camera(Camera *);

void load_camera(Camera *);