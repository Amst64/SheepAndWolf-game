#include "sheep.h"
#include <cmath>
#include "Project_SDL1.h"
#include "ground.h"

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment)
    : animal(file_path, window_surface_ptr, p_environment) {
    this->insertProprety("name", "sheep");
    std::string sexe;
    if (rand() % 2 == 0) {
        sexe = "male";
    }
    else {
        sexe = "female";
    }
    this->insertProprety("sexe", sexe);
    this->insertProprety("nature_status", "prey");
    this->insertProprety("status", "alive");
    this->set_action_time(frame_time * 1000 * death_time);

    setVel_x(2);
    setVel_y(2);
}

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos)
    : animal(file_path, window_surface_ptr,p_environment)
{
    this->insertProprety("name", "sheep");
    std::string sexe;
    if (rand() % 2 == 0) {
        sexe = "male";
    }
    else {
        sexe = "female";
    }
    this->insertProprety("sexe", sexe);
    this->insertProprety("nature_status", "prey");
    this->insertProprety("status", "alive");
    this->set_action_time(frame_time * 1000 * death_time);

    setVel_x(2);
    setVel_y(2);

    setX(xPos);
    setY(yPos);
}

sheep::~sheep() {
    //animal::~animal();
}

void sheep::move() {
    if (this->getProprety("status") == "alive") {
        auto temp = this->near_environment(); // on aura la liste de tous les animaux se trouvant à côté de l'animal mouton courant 
        int wolf_x = 0, wolf_y = 0;
        bool wolf = false;
        bool give_birth = false;
        int distance = animal_perception;

        if (temp.size() == 1) 
        {
            setVel_x(getVel_x());
            setVel_y(getVel_y());
            
            
           
        }
        else 
        {
            for (auto const& animal : temp) 
            {
                if(animal->getProprety("name") == "wolf" && animal->getProprety("status") == "alive")
                {
                    setVel_x((((getX() - animal->getX()) + animal_perception) / (1 * animal_perception)) * 4 - 1);
                    setVel_y((((getY() - animal->getY()) + animal_perception) / (1 * animal_perception)) * 4 - 1);
                }
                
                if(animal->getProprety("name") == "sheep" && animal->getProprety("status") == "alive")
                {
                    int temp_distance = std::sqrt(std::pow(animal->getX() - this->getX(), 2) + std::pow(animal->getY() - this->getY(), 2));
                    if (get_action_time() >= frame_time * 1000 * death_time + 2000) {
                        // cas où le mouton peut se reproduire
                        if (temp_distance < 1000 && this->getProprety("sexe") != animal->getProprety("sexe")) {
                            get_environnement()->add_character_at_pos("sheep.png",this->getX(), this->getY());
                            std::cout<<"Sheep spawned"<<std::endl;
                            set_action_time(0);
                        }
                    }
                    else
                    {
                        set_action_time(get_action_time() + 1);
                    }
                }
                
            }
            
        }
    }
    line_move();
}
