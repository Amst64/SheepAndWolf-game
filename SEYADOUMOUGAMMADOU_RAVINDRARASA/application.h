#pragma once

#include "Project_SDL1.h"
#include "ground.h"
#include "shepherd.h"
#include <string>
class application {
private:
    // The following are OWNING ptrs
    SDL_Window* window_ptr_;
    SDL_Surface* window_surface_ptr_;
    SDL_Event window_event_;
    unsigned last_ticks;

    // Other attributes here, for example an instance of ground

    ground arena;

public:
    application(unsigned n_sheep, unsigned n_wolf); // Ctor
    ~application();                                 // dtor

    int loop(unsigned period); // main loop of the application.
                               // this ensures that the screen is updated
                               // at the correct rate.
                               // See SDL_GetTicks() and SDL_Delay() to enforce a
                               // duration the application should terminate after
                               // 'period' seconds
};