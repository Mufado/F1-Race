#pragma once
#include <libs_init.hpp>

//Object Module Macros
#define MESHES_FILEPATH "../../../assets/meshes/"

//Game Module Macros
#define DEFAULT_COLOR glm::fvec4(0.53f, 0.81f, 0.92f, 1.0f)
#define DEBUG_COLOR   glm::fvec4(0.3f, 0.3f, 0.3f, 1.0f)

//Draw Module Macros
#define TERRAIN_SIZE          200.0f
#define HIGHWAY_WIDTH         3.0f
#define HW_TRACKS_WIDTH       0.15f
#define HW_TRACKS_LENGTH      2.0f
#define HW_TRACKS_DETACHMENT  1.0f
#define AXIS_SIZE             TERRAIN_SIZE

//Camera Module Macros
#define SIGTH_LINE_WIDTH  3.0f
#define SIGHT_SIZE        5.0f
#define SIGHT_COLOR       glm::fvec3(0.4f, 0.3f, 0.4f)

#define CAM_VIEW    glm::fvec2(2.5f, TERRAIN_SIZE)
#define CAM_UP_AXIS glm::fvec3(0.0f, 1.0f, 0.0f)

//Car Module Macros
#define DEFAULT_CAR_POS   glm::fvec3(0.0f, 0.03f, -6.0f)
#define DEFAULT_LOCAl_POS glm::fvec3(0.0f, 0.0f, 0.0f)
