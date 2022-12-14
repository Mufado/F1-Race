#pragma once
#include <libs_init.hpp>

#define PI 3.14159265359

//Object Module Macros
#define MESHES_FILEPATH   "../../../assets/meshes/"
#define CAR_FILE_NAME     "fiat.obj"
#define DEFAULT_LOCAL_POS glm::fvec3(0.0f, 0.0f, 0.0f)

//Game Module Macros
#define DEFAULT_COLOR glm::fvec4(74.0f, 158.0f, 212.0f, 1.0f) // Day: 74, 158, 212, Afternon: 242, 170, 117, Night: 1, 7, 20
#define DEBUG_COLOR   glm::fvec4(76.5f, 76.5f, 76.5f, 1.0f)

//Draw Module Macros
#define TERRAIN_SIZE  1000.0f

#define HIGHWAY_WIDTH        3.0f
#define HIGHWAY_STRIPS_WIDTH (HIGHWAY_WIDTH + 0.5f)

#define STRIPS_DIST      0.0625f //Distance between mid-left and mid-right center strip of the highway
#define STRIPS_WIDTH     0.125f
#define STRIPS_LENGHT    4.0f
#define STRIPS_SEPARATOR 3.0f //Distance between actual render center strip and the next center strip

#define AXIS_SIZE (TERRAIN_SIZE)

//Camera Module Macros
#define SIGTH_LINE_WIDTH 3.0f
#define SIGHT_SIZE       0.05f
#define SIGHT_COLOR      glm::fvec3(0.0f, 0.0f, 0.0f)

#define CAM_VIEW       glm::fvec2(2.0f, 2.0f)
#define CAM_UP_AXIS    glm::fvec3(0.0f, 1.0f, 0.0f)
#define CAM_ROTATE_ANG 5.0
#define CAM_MOVMENT    0.5f

#define VIEW_LIMIT (TERRAIN_SIZE * 0.1f) //Far distance for the frustum

//Car Object Macros
#define CAR_SIDE_MOV    0.2f
#define CAR_ACELERATION 0.1f
#define CAR_SLOWDOWN    0.2f
#define CAR_SPEEDLIMIT  1.5f

#define DEFAULT_CAR_POS glm::fvec3(0.0f, 0.01f, -6.0f)

#define HIGHWAY_LIMIT         (HIGHWAY_WIDTH - 0.5f)
#define TERRAIN_MOVMENT_LIMIT (TERRAIN_SIZE - VIEW_LIMIT)

//Car Opponents Macros
#define OPPONENTS_NUMBER         10
#define OPPONENTS_HIGHWAY_SIDE   1.5f
#define OPPONENTS_VELOCITY       1.0f
#define OPPONENTS_DISTANCE       (VIEW_LIMIT)
#define OPPONENTS_OVERPASS_LIMIT (OPPONENTS_NUMBER * OPPONENTS_DISTANCE)

#define DEFAULT_OPPONENT_POS glm::fvec3(0.0f, 0.01f, 0.0f)

//Sky Macros
#define SKY_GRADIENT 40
