#include "playable_character.h"


playable_character::playable_character(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr)
	: moving_object(window_surface_ptr, image_ptr), keyboardEvent{}
{
}


playable_character::~playable_character(){}

void playable_character::setDirection()
{
	while (SDL_PollEvent(&keyboardEvent))
	{
		
		switch (keyboardEvent.type)
		{
		case SDL_KEYDOWN:
		{
			//std::cout << "move de shepherd" << std::endl;
			if (keyboardEvent.key.keysym.sym == SDLK_RIGHT) {
				setVel_x(2);
			}
			else if (keyboardEvent.key.keysym.sym == SDLK_LEFT) {
				setVel_x(-2);
			}
			else
			{
				setVel_x(0);
			}

			if (keyboardEvent.key.keysym.sym == SDLK_UP) {
				setVel_y(-2);
			}
			else if (keyboardEvent.key.keysym.sym == SDLK_DOWN) {
				setVel_y(2);
			}
			else
			{
				setVel_y(0);
			}
		}
		}
	}
}

void playable_character::move()
{
	updateVitesse();
	setDirection();
	setX(getX() + getVel_x());
	setY(getY() + getVel_y());
}