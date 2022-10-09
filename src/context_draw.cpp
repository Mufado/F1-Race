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
    glm::mat4 projection_mat = glm::perspective(45.0f, aspect_ratio, 0.1f, 300.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection_mat));
}; 

void draw_context(Game *game)
{
    //Set default line width
    glLineWidth(5.0f);
    
    draw_sky();

    draw_terrain();

    draw_highway();

    draw_opponents();

    draw_car(game->car_bottom);

    if (game->debug_mode)
    {
        draw_debug_context(game);
    }
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

    //Vertical strip
    glBegin(GL_LINES);
        glVertex3f(camera->at.x, camera->at.y + SIGHT_SIZE, camera->at.z);
        glVertex3f(camera->at.x, camera->at.y - SIGHT_SIZE, camera->at.z);
    glEnd();

    //Horizontal strip
    glBegin(GL_LINES);
        glVertex3f(camera->at.x - SIGHT_SIZE, camera->at.y, camera->at.z);
        glVertex3f(camera->at.x + SIGHT_SIZE, camera->at.y, camera->at.z);
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
    //Highway structure and edges
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex3f(-HIGHWAY_WIDTH, 0.01f,  0.0f);
        glVertex3f( HIGHWAY_WIDTH, 0.01f,  0.0f);
        glVertex3f( HIGHWAY_WIDTH, 0.01f, -TERRAIN_SIZE);
        glVertex3f(-HIGHWAY_WIDTH, 0.01f, -TERRAIN_SIZE);
    glEnd();

    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_LINES);
        glVertex3f(-HIGHWAY_WIDTH-0.01, 0.01f,  0.0f);
        glVertex3f(-HIGHWAY_WIDTH-0.01, 0.01f, -TERRAIN_SIZE);
        glVertex3f( HIGHWAY_WIDTH-0.01, 0.01f,  0.0f);
        glVertex3f( HIGHWAY_WIDTH-0.01, 0.01f, -TERRAIN_SIZE);
    glEnd();
    //Tracks
    glColor3f(0.9f, 0.9f, 0.9f);
    
    /* Starts render track's top edge in end of the highway, then render track body until reach the start point */
    float track_top = TERRAIN_SIZE;
    for (track_top; track_top >= 0.0f; track_top -= HW_TRACKS_LENGTH + HW_TRACKS_DETACHMENT)
    {
        float track_bottom = track_top - HW_TRACKS_LENGTH;
         
        glBegin(GL_QUADS);
            glVertex3f(-HW_TRACKS_WIDTH, 0.02f, -track_bottom);
            glVertex3f( HW_TRACKS_WIDTH, 0.02f, -track_bottom);
            glVertex3f( HW_TRACKS_WIDTH, 0.02f, -track_top);
            glVertex3f(-HW_TRACKS_WIDTH, 0.02f, -track_top);
        glEnd();
    }
}

void draw_opponents() 
{

}

void draw_car(glm::fvec3 position)
{
    glm::fvec3(0.0f, 0.48f, 0.64f);
    glBegin(GL_QUADS);
        glVertex3f(position.x - 0.6f, position.y, position.z);
        glVertex3f(position.x + 0.6f, position.y, position.z);
        glVertex3f(position.x + 0.6f, position.y, position.z - 2.0f);
        glVertex3f(position.x - 0.6f, position.y, position.z - 2.0f);
    glEnd();
}
