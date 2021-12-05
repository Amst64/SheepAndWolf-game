#pragma once
#include "playable_character.h"


class shepherd : public playable_character{
public:
	shepherd(SDL_Surface* window_surface_ptr, const std::string& file_path);

	shepherd(SDL_Surface* window_surface_ptr, const std::string& file_path, int xPos, int yPos);

	~shepherd();
};