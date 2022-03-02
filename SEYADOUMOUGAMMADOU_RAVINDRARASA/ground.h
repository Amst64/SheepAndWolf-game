#pragma once 
#include "Project_SDL1.h"
#include "animal.h"
#include "sheep.h"
#include "wolf.h"
#include "shepherd_dog.h"
#include "shepherd.h"

class ground {
private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	// Some attribute to store all the wolves and sheep
	// here
	std::vector<std::shared_ptr<moving_object>> characters;

public:
	ground(SDL_Surface* window_surface_ptr); // todo: Ctor

	~ground(); // todo: Dtor, again for clean up (if necessary)
	void add_character(const std::string& file_path); // todo: Add an animal
	void add_character_at_pos(const std::string& file_path, int xPos, int yPos);
	void update(); // todo: "refresh the screen": Move animals and draw them
	std::vector<std::shared_ptr<moving_object>>& get_characters(); // geteur pour obtenir l'ensemble des perso
	// Possibly other methods, depends on your implementation
};