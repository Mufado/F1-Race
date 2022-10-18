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
    glm::mat4 projection_mat = glm::perspective(45.0f, aspect_ratio, 0.1f, VIEW_LIMIT);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection_mat));
}; 

void draw_context(Game *game)
{
    //Set default line width
    glLineWidth(5.0f);
    
    draw_sky();

    draw_ground(game);

    draw_opponents(game);

    draw_car(game->main_car);

    if (game->debug_mode)
        draw_debug_context(game);
}

void global_axis()
{
    glBegin(GL_LINES);
        //X Axis
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(AXIS_SIZE, 0.0f, 0.0f);
        glColor3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-AXIS_SIZE, 0.0f, 0.0f);

        //Y Axis
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, AXIS_SIZE, 0.0f);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -AXIS_SIZE, 0.0f);

        //Z Axis
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, AXIS_SIZE);
        glColor3f(0.0f, 0.0f, 0.5f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -AXIS_SIZE);
    glEnd();
    
    glPointSize(12.5f);

    //Origin point
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}

void camera_sight(Camera *camera)
{
    //Adjust sight width
    glLineWidth(SIGTH_LINE_WIDTH);
    
    //Sight color
    glColor3f(SIGHT_COLOR.x, SIGHT_COLOR.y, SIGHT_COLOR.z);

    glBegin(GL_LINES);
        //Vertical line
        glVertex3f(camera->at.x, camera->at.y + SIGHT_SIZE, camera->at.z);
        glVertex3f(camera->at.x, camera->at.y - SIGHT_SIZE, camera->at.z);

        //Horizontal line
        glVertex3f(camera->at.x - SIGHT_SIZE, camera->at.y, camera->at.z);
        glVertex3f(camera->at.x + SIGHT_SIZE, camera->at.y, camera->at.z);

        glVertex3f(camera->at.x, camera->at.y, camera->at.z + SIGHT_SIZE);
        glVertex3f(camera->at.x, camera->at.y, camera->at.z - SIGHT_SIZE);
    glEnd();

}

void draw_debug_context(Game *game)
{
    if(game->degub_tools)
    {
        //Always render the axis and sight even if behind objects
        glDepthFunc(GL_ALWAYS);

        global_axis();
        camera_sight(&game->camera);

        //Return depth function to its default value
        glDepthFunc(GL_LESS);
    }
}

void draw_sky()
{

}

void draw_ground(Game *game)
{
    if(game->terrain_cord.z < TERRAIN_MOVMENT_LIMIT)
        game->terrain_cord.z += game->velocity; 
    else
        game->terrain_cord.z = 0.0f;

    glTranslatef(
        game->terrain_cord.x,
        game->terrain_cord.y,
        game->terrain_cord.z
    );

    // Draw the ground objects
    draw_terrain();

    draw_highway();

    glTranslatef(
        game->terrain_cord.x,
        game->terrain_cord.y,
        -(game->terrain_cord.z)
    );
}

void draw_terrain()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(0.14f, 0.6f, 0.14f);
    glBegin(GL_QUADS);
        glVertex3f(-TERRAIN_SIZE, 0.0f, 0.0f);
        glVertex3f( TERRAIN_SIZE, 0.0f, 0.0f);
        glVertex3f( TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
        glVertex3f(-TERRAIN_SIZE, 0.0f, -TERRAIN_SIZE);
    glEnd();

    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_LINES);
        glVertex3f(-TERRAIN_SIZE, 0.01f, -TERRAIN_SIZE);
        glVertex3f( TERRAIN_SIZE, 0.01f, -TERRAIN_SIZE);
    glEnd();
}

void draw_highway()
{
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(-HIGHWAY_WIDTH, 0.01f,  0.0f);
        glVertex3f( HIGHWAY_WIDTH, 0.01f,  0.0f);
        glVertex3f( HIGHWAY_WIDTH, 0.01f, -TERRAIN_SIZE);
        glVertex3f(-HIGHWAY_WIDTH, 0.01f, -TERRAIN_SIZE);
    glEnd();

    draw_strips();
}

void draw_strips()
{
    for(int strip_cord = 0; strip_cord < TERRAIN_SIZE; strip_cord++)
    {
        if(strip_cord % 2 == 0)
            glColor3f(0.9f, 0.9f, 0.9f);
        else    
            glColor3f(1.0f, 0.0f, 0.0f);
    
        //Left Strips
        glBegin(GL_QUADS);
            glVertex3f(-HIGHWAY_WIDTH, 0.01f, -strip_cord);
            glVertex3f(-HIGHWAY_STRIPS_WIDTH, 0.01f, -strip_cord);
            glVertex3f(-HIGHWAY_STRIPS_WIDTH, 0.01f, -(strip_cord + 1));
            glVertex3f(-HIGHWAY_WIDTH, 0.01f, -(strip_cord + 1));
        glEnd();

        //Right Strips
        glBegin(GL_QUADS);
            glVertex3f(HIGHWAY_WIDTH, 0.01f, -strip_cord);
            glVertex3f(HIGHWAY_STRIPS_WIDTH, 0.01f, -strip_cord);
            glVertex3f(HIGHWAY_STRIPS_WIDTH, 0.01f, -(strip_cord + 1));
            glVertex3f(HIGHWAY_WIDTH, 0.01f, -(strip_cord + 1));
        glEnd();    
    }

    glColor3f(0.9f, 0.9f, 0.9f);
    for(float center_strip_cord = 0.0; (center_strip_cord + STRIPS_LENGHT) < TERRAIN_SIZE; center_strip_cord += STRIPS_LENGHT)
    {
        glBegin(GL_QUADS);
            glVertex3f(STRIPS_DIST, 0.02f, -center_strip_cord);
            glVertex3f((STRIPS_DIST + STRIPS_WIDTH), 0.02f, -center_strip_cord);
            glVertex3f((STRIPS_DIST + STRIPS_WIDTH), 0.02f, -(center_strip_cord + STRIPS_LENGHT));
            glVertex3f(STRIPS_DIST, 0.02f, -(center_strip_cord + STRIPS_LENGHT));
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(-STRIPS_DIST, 0.02f, -center_strip_cord);
            glVertex3f(-(STRIPS_DIST + STRIPS_WIDTH), 0.02f, -center_strip_cord);
            glVertex3f(-(STRIPS_DIST + STRIPS_WIDTH), 0.02f, -(center_strip_cord + STRIPS_LENGHT));
            glVertex3f(-STRIPS_DIST, 0.02f, -(center_strip_cord + STRIPS_LENGHT));
        glEnd();

        center_strip_cord += STRIPS_SEPARATOR;
    }
}

void draw_opponents(Game *game) 
{
    for(Object opponent : game->opponents)
    {
        glColor3f(opponent.color.x, opponent.color.y, opponent.color.z);
        glBegin(GL_TRIANGLES);
        for(glm::fvec3 vertex : opponent.obj_meshe.vertex_list)
            glVertex3f(
                vertex.x + opponent.global_position.x,
                vertex.y + opponent.global_position.y, 
                vertex.z + opponent.global_position.z
            );
        glEnd();
    
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLES);
            for(glm::fvec3 vertex : opponent.obj_meshe.vertex_list)
                glVertex3f(
                    vertex.x + opponent.global_position.x,
                    vertex.y + opponent.global_position.y, 
                    vertex.z + opponent.global_position.z
                );
        glEnd();

        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    }
}

void draw_car(Object car)
{   
    glColor3f(0.0f, 0.48f, 0.64f);
    glBegin(GL_TRIANGLES);
        for(glm::fvec3 vertex : car.obj_meshe.vertex_list)
            glVertex3f(
                vertex.x + car.global_position.x,
                vertex.y + car.global_position.y, 
                vertex.z + car.global_position.z
            );
    glEnd();

    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        for(glm::fvec3 vertex : car.obj_meshe.vertex_list)
            glVertex3f(
                vertex.x + car.global_position.x,
                vertex.y + car.global_position.y, 
                vertex.z + car.global_position.z
            );
    glEnd();

    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
}
