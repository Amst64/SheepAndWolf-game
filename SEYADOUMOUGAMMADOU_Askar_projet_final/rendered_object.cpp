#include "rendered_object.h"
#include "Project_SDL1.h"

rendered_object::rendered_object(SDL_Surface* window_surface_ptr,
    SDL_Surface* image_ptr)
    : interacting_object(), x{ frame_boundary +
                              std::rand() % (frame_width - 2 * frame_boundary) },
    y{ frame_boundary + std::rand() % (frame_height - 2 * frame_boundary) },
    window_surface_ptr_{ window_surface_ptr }, image_ptr_{ image_ptr } {

}

rendered_object::~rendered_object() { SDL_FreeSurface(image_ptr_); }

int rendered_object::getX() { return x; }
int rendered_object::getY() { return y; }

void rendered_object::setX(int _x) { x = _x; }
void rendered_object::setY(int _y) { y = _y; }

void rendered_object::draw() {
    if (this->getProprety("status") == "alive") {

        SDL_Rect rect;
        rect.x = this->getX();
        rect.y = this->getY();
        rect.w = 50;
        rect.h = 50;

        SDL_BlitScaled(this->image_ptr_, NULL, window_surface_ptr_, &rect);
    }
}