#include "shepherd.h"


shepherd::shepherd(SDL_Surface* window_surface_ptr, const std::string& file_path)
	:playable_character(window_surface_ptr, IMG_Load(file_path.c_str()))
{
	setProprety("name", "shepherd");
	this->insertProprety("sexe", "male");
	this->insertProprety("nature_status", "hunter");
	this->insertProprety("status", "alive");

	setX(400);
	setY(300);

	setVel_x(0);
	setVel_y(0);
}

shepherd::shepherd(SDL_Surface* window_surface_ptr, const std::string& file_path, int xPos, int yPos)
	:playable_character(window_surface_ptr, IMG_Load(file_path.c_str()))
{
	setProprety("name", "shepherd");
	this->insertProprety("sexe", "male");
	this->insertProprety("nature_status", "hunter");
	this->insertProprety("status", "alive");

	setX(xPos);
	setY(yPos);

	setVel_x(0);
	setVel_y(0);
}

shepherd::~shepherd()
{
}