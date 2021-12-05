#pragma once
#include "animal.h"
#include <math.h>

class shepherd_dog : public animal{
public:
	shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment);

	shepherd_dog(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos);

	~shepherd_dog();

	void move() override;

	void setPos(int xShepherd, int yShepherd);

	void increaseStep();

	void findShepherdPos();

private:
	int stepToCircle;
	float step;

	//attribut pour la position du berger
	int shepherdPosX; 
	int shepherdPosY;
};