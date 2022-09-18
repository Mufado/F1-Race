#include <context_draw.hpp>

void project_init()
{
    glEnable(GL_DEPTH_TEST);
}

void load_buffers()
{
    glClearColor(background_color.x, background_color.y, background_color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void perspective_init(sf::Window *window)
{
    window_size = window->getSize();

    glViewport(0, 0, window_size.x, window_size.y);

    load_buffers();

    float aspect_ratio = (float) (window_size.x / window_size.y);

    glm::mat4 idt_mat = glm::mat4(1.0);
    glLoadMatrixf(glm::value_ptr(idt_mat));

    glMatrixMode(GL_PROJECTION);

    glm::mat4 proj_mat = glm::perspective(60.f, aspect_ratio, 1.f, 1000.f);

    glLoadMatrixf(glm::value_ptr(proj_mat));
}; 

void draw_context()
{
    draw_sky();

    draw_terrain();

    draw_highway();

    draw_opponents();

    draw_car();
}

void draw_sky()
{

}

void draw_terrain()
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