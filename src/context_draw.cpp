#include <context_draw.hpp>

void ortho_init()
{
    glm::mat4 idt_mat = glm::mat4(1.0);
    glLoadMatrixf(glm::value_ptr(idt_mat));

    glMatrixMode(GL_PROJECTION);

    glm::mat4 proj_mat = glm::ortho(
         0.f, 100.f,
         0.f, 100.f,
        -1.f,   1.f
    );

    glLoadMatrixf(glm::value_ptr(proj_mat));
}