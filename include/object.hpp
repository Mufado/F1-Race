#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <libs_init.hpp>

typedef struct
{
    std::vector<glm::fvec3> vertex_list;
} Mesh;

typedef struct 
{
    glm::fvec3 global_position;
    glm::fvec3 color;
    
    Mesh obj_meshe;
} Object;

Object load_obj_from_file(const std::string);
