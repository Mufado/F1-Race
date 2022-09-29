#include <camera.hpp>

#include <macros.hpp>

void start_camera(Camera *camera)
{
    //Camera always be above main car, looking where the terrain ends
    camera->eye = glm::fvec3(0.0f, CAM_HEIGHT, 0.0f);
    camera->at  = glm::fvec3(camera->eye.x, (camera->eye.y) - CAM_HEIGHT, (camera->eye.z) - TERRAIN_SIZE);
    camera->up  = glm::fvec3(0.0f, 1.0, 0.0F); 
}

void load_camera(Camera *camera)
{
    camera->at = glm::fvec3(camera->eye.x, (camera->eye.y) - CAM_HEIGHT, (camera->eye.z) - TERRAIN_SIZE);

    glm::mat4 view_mat = glm::lookAt(camera->eye, camera->at, camera->up);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view_mat));
}
