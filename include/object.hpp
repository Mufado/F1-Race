#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <glm/ext.hpp>

typedef struct
{
    glm::fvec3 position;
} Vertex;

typedef struct
{
    std::vector<Vertex> vertex_list;
} Meshe;

typedef struct 
{
    Meshe obj_meshe; 

} Object;

Object load_obj_from_file(const std::string);
