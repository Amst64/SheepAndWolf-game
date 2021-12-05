#include "moving_object.h"
#include "Project_SDL1.h"



moving_object::moving_object(SDL_Surface* window_surface_ptr,
    SDL_Surface* image_ptr)
    : rendered_object(window_surface_ptr, image_ptr), velocity_x{ 1 }, velocity_y{ 1 }
{

}

moving_object::~moving_object() {/* rendered_object::~rendered_object();*/ }

int moving_object::getVel_x() { return velocity_x; }
int moving_object::getVel_y() { return velocity_y; }

void moving_object::setVel_x(int _velX) { velocity_x = _velX; }
void moving_object::setVel_y(int _velY) { velocity_y = _velY; }

void moving_object::updateVitesse() {
    if (getX() >= frame_width - 100) {
        moving_object::setVel_x(-moving_object::getVel_x());
    }

    if (getY() >= frame_height - 100) {
        moving_object::setVel_y(-moving_object::getVel_y());
    }

    if (getX() == 0) {
        moving_object::setVel_x(-moving_object::getVel_x());
    }

    if (getY() == 0) {
        moving_object::setVel_y(-moving_object::getVel_y());
    }
}