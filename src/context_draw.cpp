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
    //Set default line width
    glLineWidth(5.f);
    
    draw_sky();

    draw_terrain();

    draw_highway();

    draw_opponents();

    draw_car();

    if (game->debug_mode)
        draw_debug_context(game);
}

void global_axis()
{
    //X Axis
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(TERRAIN_SIZE, 0.0f, 0.0f);
    glEnd();

    glColor3f(0.5f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-TERRAIN_SIZE, 0.0f, 0.0f);
    glEnd();

    //Y Axis
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, TERRAIN_SIZE, 0.0f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -TERRAIN_SIZE, 0.0f);
    glEnd();

    //Z Axis
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, TERRAIN_SIZE);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -TERRAIN_SIZE);
    glEnd();
    
    glPointSize(12.5f);

    //Origin
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}

void camera_sight(Camera *camera)
{
    //Adjust sight width
    glLineWidth(SIGTH_WIDTH);
    
    //Vertical strip
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(camera->at.x, camera->at.y + SIGHT_SIZE, camera->at.z);
        glVertex3f(camera->at.x, camera->at.y - SIGHT_SIZE, camera->at.z);
    glEnd();

    //Horizontal strip
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(camera->at.x - SIGHT_SIZE, camera->at.y, camera->at.z);
        glVertex3f(camera->at.x + SIGHT_SIZE, camera->at.y, camera->at.z);
    glEnd();
}

void draw_debug_context(Game *game)
{
    if(game->cartesian)
        global_axis();

    camera_sight(&game->camera);
}

void draw_sky()
{

}

void draw_terrain()
{
    glColor3f(0.14f, 0.6f, 0.14f);
    glBegin(GL_QUADS);
        glVertex3f(-TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
        glVertex3f( TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
        glVertex3f( TERRAIN_SIZE, 0.0f,  TERRAIN_SIZE);
        glVertex3f(-TERRAIN_SIZE, 0.0f,  TERRAIN_SIZE);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
        glVertex3f( TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
        glVertex3f( TERRAIN_SIZE, 0.0f,  TERRAIN_SIZE);
        glVertex3f(-TERRAIN_SIZE, 0.0f,  TERRAIN_SIZE);
    glEnd();
}

void draw_highway()
{
    glColor3f(0.185f, 0.185f, 0.185f);
    glBegin(GL_QUADS);
        glVertex3f(-HIGHWAY_WIDTH, 0.0f, -TERRAIN_SIZE);
        glVertex3f( HIGHWAY_WIDTH, 0.0f, -TERRAIN_SIZE);
        glVertex3f( HIGHWAY_WIDTH, 0.0f,  TERRAIN_SIZE);
        glVertex3f(-HIGHWAY_WIDTH, 0.0f,  TERRAIN_SIZE);
    glEnd();
}

void draw_opponents()
{

}

void draw_car()
{

}