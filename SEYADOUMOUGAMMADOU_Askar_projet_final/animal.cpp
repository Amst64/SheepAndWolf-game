
#include "declaration.h"
#include "animal.h"
#include <cmath>
#include "ground.h"

animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment)
    : moving_object(window_surface_ptr, IMG_Load(file_path.c_str())), environment{ p_environment },action_time{ 0 }
{

}


animal::~animal() { /*moving_object::~moving_object();*/ }

std::vector<std::shared_ptr<moving_object>> animal::near_environment() {
    int r;
    if(this->getProprety("name") == "doggo")
    {
        r = 1000;
    }
    else if(this->getProprety("name") == "sheep")
    {
        r = animal_perception;
    }
    else
    {
        r = 90;
    }
    
    auto environment_vector = this->environment->get_characters();
    std::vector<std::shared_ptr<moving_object>> near_animals;
    for (auto const& animal : environment_vector) {
        // pour chaque animal on regarde sa distance par rapport à l'animal sur lequel on travaille
        auto distance_x = std::pow(animal->getX() - this->getX(), 2);
        auto distance_y = std::pow(animal->getY() - this->getY(), 2);
        if (std::sqrt(distance_x + distance_y) < r) {
            // l'animal est dans un rayon proche de l'animal courant 
            near_animals.push_back(animal);
        }
    }
    return near_animals;
}

void animal::line_move() {

    updateVitesse();
    setX(getX() + getVel_x());
    setY(getY() + getVel_y());
}

void animal::set_action_time(int new_action_time) { action_time = new_action_time; }
int animal::get_action_time() { return this->action_time; }
ground* animal::get_environnement() { return this->environment; }
