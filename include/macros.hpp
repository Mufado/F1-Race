#pragma once
#include <libs_init.hpp>

#define PI 3.14159265359

//Object Module Macros
#define MESHES_FILEPATH   "../../../assets/meshes/"
//#define CAR_FILE_NAME "fiat.obj"
#define CAR_FILE_NAME "f1_car.obj"
#define DEFAULT_LOCAL_POS glm::fvec3(0.0f, 0.0f, 0.0f)

//Game Module Macros
#define DEFAULT_COLOR glm::fvec4(0.53f, 0.81f, 0.92f, 1.0f)
#define DEBUG_COLOR   glm::fvec4(0.3f, 0.3f, 0.3f, 1.0f)

//Draw Module Macros
#define TERRAIN_SIZE         200.0f
#define HIGHWAY_WIDTH        6.0f
#define HIGHWAY_STRIPS_WIDTH (HIGHWAY_WIDTH + 0.5f)
#define TRACKS_SIZE          glm::fvec2(0.15f, 2.0f)
#define TRACKS_DETACHMENT    2.0f
#define STRIPS_DIST          0.25f
#define STRIPS_LENGHT        2.0f
#define STRIPS_SEPARATOR     1.0f
#define AXIS_SIZE            (TERRAIN_SIZE)

//Camera Module Macros
#define SIGTH_LINE_WIDTH 3.0f
#define SIGHT_SIZE       5.0f
#define SIGHT_COLOR      glm::fvec3(0.4f, 0.3f, 0.4f)

#define CAM_VIEW    glm::fvec2(2.0f, 2.0f)
#define CAM_UP_AXIS glm::fvec3(0.0f, 1.0f, 0.0f)
#define CAM_ROTATE_ANG 5.0

//Car Object Macros
#define DEFAULT_CAR_POS glm::fvec3(0.0f, 0.5f, -6.0f)
#define CAR_SIDE_MOV 0.2f
#define HIGHWAY_LIMIT (HIGHWAY_WIDTH - 0.5f)
