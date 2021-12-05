
#include "shepherd_dog.h"



shepherd_dog::shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment):
	animal(file_path, window_surface_ptr, p_environment), stepToCircle{100}, step{0}, shepherdPosX{0}, shepherdPosY{0}
{
    this->insertProprety("name", "doggo");
    std::string sexe;
    if (rand() % 2 == 0) {
        sexe = "male";
    }
    else {
        sexe = "female";
    }
    this->insertProprety("sexe", sexe);
    this->insertProprety("nature_status", "hunter");
    this->insertProprety("status", "alive");

    setX(400);
    setY(300);
}

shepherd_dog::shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos)
    :animal(file_path, window_surface_ptr, p_environment), stepToCircle{ 100 }, step{ 0 }, shepherdPosX{ 0 }, shepherdPosY{ 0 }
{
    this->insertProprety("name", "doggo");
    std::string sexe;
    if (rand() % 2 == 0) {
        sexe = "male";
    }
    else {
        sexe = "female";
    }
    this->insertProprety("sexe", sexe);
    this->insertProprety("nature_status", "hunter");
    this->insertProprety("status", "alive");

    setX(xPos);
    setY(yPos);
}

shepherd_dog::~shepherd_dog()
{
}

void shepherd_dog::move()
{
    findShepherdPos();
    setPos(shepherdPosX, shepherdPosY);
    increaseStep();
}

void shepherd_dog::setPos(int xShepherd, int yShepherd) {
	setX((xShepherd) + cos((step / stepToCircle) * 2 * 3.14f) * 100);
	setY((yShepherd) + sin((step / stepToCircle) * 2 * 3.14f) * 100);
}

void shepherd_dog::increaseStep() {
    if(step == stepToCircle)
    {
        step = 0;
    }
    else
    {
        step = step + 0.5f;
    }
}

void shepherd_dog::findShepherdPos()
{
    auto aliveCharacters = near_environment();

    for(auto character : aliveCharacters)
    {
        if(character->getProprety("name") == "shepherd" && character->getProprety("status") == "alive")
        {
            shepherdPosX = character->getX();
            shepherdPosY = character->getY();
        }
    }
}
