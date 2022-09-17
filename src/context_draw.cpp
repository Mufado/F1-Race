#include <context_draw.hpp>

void project_init()
{
    glEnable(GL_DEPTH_TEST);
}

void perspective_init(sf::Window *window)
{
    sf::Vector2u windows_size = window->getSize();
    float aspect_ratio = (float) (windows_size.x / windows_size.y);

    glm::mat4 identity_mat = glm::mat4(1.0f);
    glLoadMatrixf(glm::value_ptr(identity_mat));

    glMatrixMode(GL_PROJECTION);

    glm::mat4 projection_mat = glm::perspective(60.0f, aspect_ratio, 1.0f, 1000.0f);

    glLoadMatrixf(glm::value_ptr(projection_mat));
}; 

void draw_context()
{
    draw_sky();

    draw_highway();

    draw_opponents();

    draw_car();
}

void draw_sky()
{

}

void draw_highway()
{

}

void draw_opponents()
{

}

void draw_car()
{

}