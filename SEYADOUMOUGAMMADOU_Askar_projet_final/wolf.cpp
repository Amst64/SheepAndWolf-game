
#include "wolf.h"


wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment)
    : animal(file_path, window_surface_ptr, p_environment) {
    // ajout des caractéristiques du loup dans le vecteur properties de interacting_object
    this->insertProprety("name", "wolf");
    this->insertProprety("sexe", "male");
    this->insertProprety("nature_status", "hunter");
    this->insertProprety("status", "alive");

}

wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos)
    :animal(file_path, window_surface_ptr, p_environment)
{
    // ajout des caractéristiques du loup dans le vecteur properties de interacting_object
    this->insertProprety("name", "wolf");
    this->insertProprety("sexe", "male");
    this->insertProprety("nature_status", "hunter");
    this->insertProprety("status", "alive");

    setX(xPos);
    setY(yPos);
}

wolf::~wolf() {
    // animal::~animal();

}

void wolf::move() {

    if (this->getProprety("status") == "alive") {
        if (get_action_time() < frame_time * 1000 * death_time) {
            auto temp = this->near_environment();
            int distance = animal_perception;

            for (auto const& animal : temp) {
                if (std::sqrt(std::pow(animal->getX() - this->getX(), 2) + std::pow(animal->getY() - this->getY(), 2)) < distance && animal->getProprety("name") == "sheep" && animal->getProprety("status") == "alive") 
                {
                    animal->setProprety("status", "dead");
                    std::cout << "Un loup vient de manger un mouton" << std::endl;
                    set_action_time(0);
                }

                if (animal->getProprety("name") == "doggo" && animal->getProprety("status") == "alive")
                {
                    setVel_x((((getX() - animal->getX()) + animal_perception) / (1 * animal_perception)) * 4 - 1);
                    setVel_y((((getY() - animal->getY()) + animal_perception) / (1 * animal_perception)) * 4 - 1);

                }
            }
            
            set_action_time(get_action_time() + 1);
        }
        else {
            this->setProprety("status", "dead");
        }
    }
    else {
        return; // l'animal est mort 
    }
    line_move();
}