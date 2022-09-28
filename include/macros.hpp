#pragma once
#include <glm/ext.hpp>

//Draw Module Macros
#define TERRAIN_SIZE  200.0f
#define AXIS_SIZE     TERRAIN_SIZE
#define HIGHWAY_WIDTH 3.0f

//Camera Module Macros
#define SIGTH_LINE_WIDTH  3.0f
#define SIGHT_SIZE        5.0f
#define SIGHT_COLOR glm::fvec3(0.4f, 0.3f, 0.4f)

#define CAM_VIEW    glm::fvec2(2.5F, TERRAIN_SIZE)
#define CAM_UP_AXIS glm::fvec3(0.0f, 1.0f, 0.0f) 
