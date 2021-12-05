#pragma once

#include "animal.h"

// Insert here:
// class sheep, derived from animal
class sheep : public animal {

public:
	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment);

	sheep(const std::string& file_path, SDL_Surface* window_surface_ptr, ground* p_environment, int xPos, int yPos);

	~sheep();

	void move() override;

};