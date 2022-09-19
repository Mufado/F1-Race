#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <libs_init.hpp>

#define MESHES_FILEPATH "../../../assets/meshes/"

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
