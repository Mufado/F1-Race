#include <camera.hpp>

void start_camera(Camera *camera)
{
    camera->eye = glm::fvec3(2.0f, 2.0f, 2.0f);
    camera->at  = glm::fvec3(camera->eye.x, camera->eye.y, (camera->eye.z) - 2.0f);
    camera->up  = glm::fvec3(0.0f, 1.0f, 0.0f); 
}

void load_camera(Camera *camera)
{
    camera->at = glm::fvec3(camera->eye.x, camera->eye.y, (camera->eye.z) - 2.0f);

    glMatrixMode(GL_MODELVIEW);

    glm::mat4 view_mat = glm::lookAt(camera->eye, camera->at, camera->up);
    glLoadMatrixf(glm::value_ptr(view_mat));
}