#pragma once

#include "rendered_object.h"


class moving_object : public rendered_object {
public:

	moving_object(SDL_Surface* window_surface_ptr, SDL_Surface* image_ptr);

	~moving_object();

	virtual void move() = 0;

	int getVel_x();
	int getVel_y();

	void setVel_x(int _velX);
	void setVel_y(int _velY);

	void updateVitesse(); // fonction pour mettre à jour les vitesses pour pas que les animaux se téléporte en bordure 


private:
	int velocity_x, velocity_y;


};