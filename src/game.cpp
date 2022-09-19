#include <game.hpp>

void project_init(Game game)
{
    game.window->setFramerateLimit(60);
    game.window->setKeyRepeatEnabled(true);

    glEnable(GL_DEPTH_TEST);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPointSize(10.f);
    glLineWidth(5.f);
}