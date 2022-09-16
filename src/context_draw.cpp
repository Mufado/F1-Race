#include <context_draw.hpp>

void project_init()
{
    glEnable(GL_DEPTH_TEST);
}

void perspective_init(sf::Window *window)
{
    sf::Vector2u windows_size = window->getSize();
    float aspect_ratio = (float) (windows_size.x / windows_size.y);

    glm::mat4 idt_mat = glm::mat4(1.0);
    glLoadMatrixf(glm::value_ptr(idt_mat));

    glMatrixMode(GL_PROJECTION);

    glm::mat4 proj_mat = glm::perspective(60.f, aspect_ratio, 1.f, 1000.f);

    glLoadMatrixf(glm::value_ptr(proj_mat));
}; 