#include <camera.hpp>

void start_camera(Camera *camera)
{
    camera->eye = glm::fvec3(0.0f, CAM_VIEW.x, 0.0f);
    camera->at  = glm::fvec3(camera->eye.x, (camera->eye.y) - CAM_VIEW.x, (camera->eye.z) - CAM_VIEW.y);
    camera->up  = CAM_UP_AXIS; 
}

void load_camera(Camera *camera)
{    
    glm::mat4 view_mat = glm::lookAt(camera->eye, camera->at, camera->up);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view_mat));
}
