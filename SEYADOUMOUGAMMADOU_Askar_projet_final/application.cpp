#include "application.h"
#include "ground.h"
#include "animal.h"
application::application(unsigned int n_sheep, unsigned int n_wolf)
    : window_ptr_{ SDL_CreateWindow("Sheep and Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0) }
    , window_surface_ptr_{ SDL_GetWindowSurface(window_ptr_) }, window_event_{}, last_ticks(SDL_GetTicks()), arena{ ground(window_surface_ptr_)}
{


    for (int i = 0; i < n_sheep; i++)
    {
        arena.add_character("media/sheep.png");
    }

    for (int i = 0; i < n_wolf; i++)
    {
        arena.add_character("media/wolf.png");
    }
    
    arena.add_character("media/doggo.png");
    std::string file_path_doggo = "media/doggo.png";
    arena.add_character("media/shepherd.png");
}

application::~application() {
    SDL_FreeSurface(window_surface_ptr_);
    SDL_DestroyWindow(window_ptr_);
    SDL_Quit();
}

int application::loop(unsigned int period) {
    unsigned start_tick = SDL_GetTicks();
    last_ticks = SDL_GetTicks();
    bool keep_window_open = true;
    while (keep_window_open && ((SDL_GetTicks() - start_tick) < period * 1000)) {
        while (SDL_PollEvent(&window_event_) > 0) {
            switch (window_event_.type) {
                case SDL_QUIT:
                {
                    keep_window_open = false;
                    break;
                }
            }
        }

        SDL_FillRect(window_surface_ptr_, NULL,
            SDL_MapRGB(window_surface_ptr_->format, 0, 255, 127));


        arena.update();

        unsigned nt = SDL_GetTicks();
        if ((nt - last_ticks) < frame_time * 1000) {
            SDL_Delay((unsigned)((frame_time * 1000) - (nt - last_ticks)));
        }
        SDL_UpdateWindowSurface(window_ptr_);
        last_ticks = SDL_GetTicks();
    }

    // boucle qui va compter le nombre de moutons en vie 
    int final_score = 0;
    for (auto const& animal : arena.get_characters()) {
        if (animal->getProprety("name") == "sheep" && animal->getProprety("status") == "alive") {
            final_score++;
        }
    }
    std::cout << "Le score final du joueur est " << final_score << std::endl;
    return 0;
}