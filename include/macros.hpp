#pragma once
#include <libs_init.hpp>

#define PI 3.14159265359

//Object Module Macros
#define MESHES_FILEPATH   "../../../assets/meshes/"
#define DEFAULT_LOCAL_POS glm::fvec3(0.0f, 0.0f, 0.0f)

//Game Module Macros
#define DEFAULT_COLOR glm::fvec4(0.53f, 0.81f, 0.92f, 1.0f)
#define DEBUG_COLOR   glm::fvec4(0.3f, 0.3f, 0.3f, 1.0f)

//Draw Module Macros
#define TERRAIN_SIZE  200.0f
#define HIGHWAY_WIDTH 3.0f
#define TRACKS_SIZE   glm::fvec3(0.15f, 2.0f, 1.0f) //Width, Length, Detachment
#define AXIS_SIZE     TERRAIN_SIZE

//Camera Module Macros
#define SIGTH_LINE_WIDTH 3.0f
#define SIGHT_SIZE       5.0f
#define SIGHT_COLOR      glm::fvec3(0.4f, 0.3f, 0.4f)

#define CAM_VIEW    glm::fvec2(2.0f, 2.0f)
#define CAM_UP_AXIS glm::fvec3(0.0f, 1.0f, 0.0f)
#define CAM_ROTATE_ANG 5.0

//Car Object Macros
#define DEFAULT_CAR_POS glm::fvec3(0.0f, 0.5f, -6.0f)
