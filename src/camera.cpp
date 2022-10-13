#include <camera.hpp>

void start_camera(Camera *camera)
{
    camera->eye = glm::fvec3(0.0f, CAM_VIEW.x, 0.0f);
    camera->at  = glm::fvec3(camera->eye.x, (camera->eye.y), (camera->eye.z) - CAM_VIEW.x);
    camera->up  = CAM_UP_AXIS; 
}

void load_camera(Camera *camera)
{    
    glm::mat4 view_mat = glm::lookAt(camera->eye, camera->at, camera->up);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view_mat));
}

void rotate_camera(Camera *camera, double angule)
{
    double radian = (angule * PI) / 180.0;

    glm::fvec2 rotate_lookat = glm::fvec2(
        (cos(radian) * 0.0) - (sin(radian) * CAM_VIEW.x),
        (sin(radian) * 0.0) + (cos(radian) * CAM_VIEW.x)
    );

    camera->at  = glm::fvec3(
        (camera->eye.x) + rotate_lookat.x, 
        (camera->eye.y), 
        (camera->eye.z) - rotate_lookat.y
    );
}
