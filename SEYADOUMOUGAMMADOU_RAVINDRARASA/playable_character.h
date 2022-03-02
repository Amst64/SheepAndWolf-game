#pragma once  
#include "moving_object.h"
#include "animal.h"

class playable_character : public moving_object {
public:
    playable_character(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr);

    ~playable_character();

    void setDirection();

    void move() override;

private:
    SDL_Event keyboardEvent;
};