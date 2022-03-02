#pragma once

#include "interacting_object.h"



class rendered_object : public interacting_object {

public:
    rendered_object(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr);

    ~rendered_object();

    int getX();
    int getY();

    void setX(int _x);
    void setY(int _y);

    void draw();

private:
    int x, y;

    SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                      // animal to be drawn, also non-owning

    SDL_Surface* image_ptr_;    // The texture of the sheep (the loaded image), use
                                // load_surface_for
};