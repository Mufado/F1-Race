#include <context_draw.hpp>

void load_viewport(Game *game)
{
    game->window_size = game->window->getSize();

    glViewport(0, 0, game->window_size.x, game->window_size.y);

    glClearColor(game->background_color.x, game->background_color.y, game->background_color.z, game->background_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void perspective_init(Game *game)
{
    load_viewport(game);

    float aspect_ratio = float(game->window_size.x) / float(game->window_size.y);

    glm::mat4 identity_mat = glm::mat4(1.0f);
    glLoadMatrixf(glm::value_ptr(identity_mat));

    glMatrixMode(GL_PROJECTION);

    glm::mat4 projection_mat = glm::perspective(60.0f, aspect_ratio, 0.1f, 500.0f);

    glLoadMatrixf(glm::value_ptr(projection_mat));
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
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex3f(1.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, -1.0f, -1.0f);
        glVertex3f(3.0f, 0.0f, -1.0f);
    glEnd();
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