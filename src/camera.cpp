#include <camera.hpp>

void start_camera(Camera *camera)
{
    camera->eye = glm::fvec3(0.0f, CAM_VIEW.x, 0.0f);
    camera->at  = glm::fvec3(camera->eye.x, (camera->eye.y) - CAM_VIEW.x, (camera->eye.z) - CAM_VIEW.y);
    camera->up  = CAM_UP_AXIS; 
}

void load_camera(Camera *camera, float player_x, bool debug_mode)
{
    if(!debug_mode)
    {
        camera->eye = glm::fvec3(player_x, camera->eye.y, camera->eye.z);
    }
    
    camera->at  = glm::fvec3(camera->eye.x, (camera->eye.y) - CAM_VIEW.x, (camera->eye.z) - CAM_VIEW.y);

    glm::mat4 view_mat = glm::lookAt(camera->eye, camera->at, camera->up);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view_mat));
}
