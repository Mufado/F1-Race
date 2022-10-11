#include <object.hpp>

Object load_obj_from_file(const std::string obj_file)
{
    Object loaded_obj;

    //Vertexs
    std::vector<glm::fvec3> vertexs_positions;
    //Faces
    std::vector<GLint>      vertexs_indicies;
    
    //Vertexs e temp array
    std::vector<glm::fvec3>  polygon_vertexs;

    std::stringstream str_stream;
    std::ifstream     in_file(MESHES_FILEPATH + obj_file);

    std::string       line        = "",
                      line_prefix = "";

    //Aux atributes 
    GLint     aux_glint = 0;
    glm::vec2 aux_vec2; 
    glm::vec3 aux_vec3;

    if(!in_file.is_open())
        throw "ERRO: Can't open the file !";

    while(std::getline(in_file, line))
    {
        str_stream.clear();
        str_stream.str(line);
        str_stream >> line_prefix;

        if(line_prefix == "v")
        {
            str_stream >> aux_vec3.x >> aux_vec3.y >> aux_vec3.z;
            vertexs_positions.push_back(aux_vec3);
        }
        else if(line_prefix == "f")
        {
            int32_t counter = 0;
            while(str_stream >> aux_glint)
            {
                if(counter == 0)
                    vertexs_indicies.push_back(aux_glint);

                if(str_stream.peek() == '/')
                {
                    counter++;
                    str_stream.ignore(1, '/');
                }
                else if(str_stream.peek() == ' ')
                {
                    counter++;
                    str_stream.ignore(1, ' ');
                }

                if(counter > 2)
                    counter = 0;
            }
        }

        polygon_vertexs.resize(
            vertexs_indicies.size(),
            glm::fvec3()                    
        );

        for(size_t i = 0; i < polygon_vertexs.size(); i++)
            polygon_vertexs[i] = vertexs_positions[vertexs_indicies[i] - 1];

    }

    loaded_obj.obj_meshe.vertex_list = polygon_vertexs;

    return loaded_obj;
}