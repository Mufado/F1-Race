#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <libs_init.hpp>

#define MESHES_FILEPATH "../../../assets/meshes/"

typedef struct
{
    glm::fvec3 position;
    glm::fvec3 normal_vector;
    glm::fvec2 texture_coordinate;
} Vertex;

typedef struct
{
    std::vector<Vertex>  vertex_list;
    std::vector<int32_t> face_indices;
} Meshe;

typedef struct 
{
    glm::fvec3 global_position;
    glm::fvec3 local_position;
    glm::fvec3 color;
    
    Meshe obj_meshe; 
} Object;

Object load_obj_from_file(const std::string);
