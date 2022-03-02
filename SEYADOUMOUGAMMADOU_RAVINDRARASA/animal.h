#pragma once

#include "moving_object.h"
#include "declaration.h"


class animal :public moving_object {

public:
    animal(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment);

    ~animal(); // todo: Use the destructor to release memory and "clean up
               // behind you"


    virtual void move() = 0; // Animals move around, but in a different
                             // fashion depending on which type of animal
    // fonction qui retourne la liste des animaux les plus proches (une référence pour ne pas faire de copie + const pour ne pas modifier les animaux) 
    std::vector<std::shared_ptr<moving_object>> near_environment();

    // fonction qui fait avance les animaux sans rien prendre en compte 
    void line_move();

    ground* get_environnement();
    int get_action_time();
    void set_action_time(int new_action_time);


private:
    ground* environment; // attribut qui va garder un pointeur vers ground 
    int action_time;

};