#pragma once

#include "animal.h"
#include "Project_SDL1.h"
#include <cmath>


class wolf : public animal {

public:
	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment);

	wolf(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos);

	~wolf();

	void move() override;
};