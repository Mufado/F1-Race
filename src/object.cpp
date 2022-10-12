#include <object.hpp>

Object load_obj_from_file(const std::string obj_file)
{
    Object loaded_object;
    
    std::ifstream filestream{ MESHES_FILEPATH + obj_file };

    if (!filestream || !filestream.is_open())
        throw "ERRO: Can't open the file !";

    std::vector<glm::vec3> vertex_list;

    glm::vec3 vertex{};
    glm::vec3 indice{};

    for (std::string line; std::getline(filestream, line); )
    {
        if (line.empty())
            continue;

        size_t index{ line.find_first_of(' ') };

        std::string_view line_view = line;
        std::string_view prefix = line_view.substr(0, index);
        std::string_view target = line_view.substr(index);

        std::istringstream stream{ target.data() };

        if (prefix == "v")
        {
            if (stream >> vertex.x >> vertex.y >> vertex.z)
                vertex_list.push_back(std::move(vertex));

            stream.ignore('\n');
            if (stream)
                throw "Vertex Coordinates must be 3D";
        }
        else if (prefix == "f")
        {
            std::size_t vertex_index{};
            char delim{};

            while (stream >> vertex_index)
                loaded_object.obj_meshe.vertex_list.emplace_back(std::move(vertex_list[vertex_index - 1u]));
        }
    }

    return loaded_object;
}