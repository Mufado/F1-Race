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

    glm::mat4 projection_mat = glm::perspective(45.0f, aspect_ratio, 0.1f, 500.0f);

    glLoadMatrixf(glm::value_ptr(projection_mat));
}; 

void draw_context(Game *game)
{
    draw_sky();

    draw_terrain();

    draw_highway();

    draw_opponents();

    draw_car();

    if (game->debug_mode)
        draw_debug_context(game);
}

void global_axis(float axis_size)
{
    //X Axis
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(axis_size, 0.0f, 0.0f);
    glEnd();

    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-axis_size, 0.0f, 0.0f);
    glEnd();

    //Y Axis
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, axis_size, 0.0f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -axis_size, 0.0f);
    glEnd();

    //Z Axis
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, axis_size);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -axis_size);
    glEnd();

    //Origin
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}

void camera_sight(Camera *camera)
{
    glLineWidth(2.f);
    
    //Vertical strip
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(camera->at.x, camera->at.y + 0.02f, camera->at.z);
        glVertex3f(camera->at.x, camera->at.y - 0.02f, camera->at.z);
    glEnd();

    //Horizontal strip
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(camera->at.x - 0.02f, camera->at.y, camera->at.z);
        glVertex3f(camera->at.x + 0.02f, camera->at.y, camera->at.z);
    glEnd();

    glLineWidth(5.f);
}

void draw_debug_context(Game *game)
{
    global_axis(game->axis_size);

    camera_sight(&game->camera);
}

void draw_sky()
{

}

void draw_terrain()
{
    glColor3f(0.14f, 0.6f, 0.14f);
    glBegin(GL_QUADS);
        glVertex3f(-15.0f, 0.0f, -15.0f);
        glVertex3f(15.0f, 0.0f, -15.0f);
        glVertex3f(15.0f, 0.0f, 15.0f);
        glVertex3f(-15.0f, 0.0f, 15.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-15.0f, 0.0f, -15.0f);
        glVertex3f(15.0f, 0.0f, -15.0f);
        glVertex3f(15.0f, 0.0f, 15.0f);
        glVertex3f(-15.0f, 0.0f, 15.0f);
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