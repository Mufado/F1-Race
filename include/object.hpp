#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <libs_init.hpp>

//Commented is for the part 2 !

// typedef struct
// {
//     glm::fvec3 position;
//     // glm::fvec3 normal_vector;
//     // glm::fvec2 texture_coordinate; 
// } Vertex;

typedef struct
{
    std::vector<glm::fvec3> vertex_list;
    // std::vector<int32_t> face_indices;
} Mesh;

typedef struct 
{
    glm::fvec3 global_position;
    // glm::fvec3 local_position;
    glm::fvec3 color;
    
    Mesh obj_meshe;
} Object;

Object load_obj_from_file(const std::string);
