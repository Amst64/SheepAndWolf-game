#pragma once  
#include "ground.h"

ground::ground(SDL_Surface* window_surface_ptr)
    :window_surface_ptr_{ window_surface_ptr }, characters{ std::vector<std::shared_ptr<moving_object>>() }
{

}


ground::~ground()
{

}

void ground::add_character(const std::string& file_path)
{
    if (file_path == "media/sheep.png") {
        characters.push_back(std::make_shared<sheep>(file_path.c_str(), this->window_surface_ptr_, this));
    }
    else if (file_path == "media/wolf.png") {
        characters.push_back(std::make_shared<wolf>(file_path.c_str(), this->window_surface_ptr_, this));
    }
    else if (file_path == "media/doggo.png") {
        characters.push_back(std::make_shared<shepherd_dog>(file_path.c_str(), this->window_surface_ptr_, this));
    }
    else if (file_path == "media/shepherd.png") {
        characters.push_back(std::make_shared<shepherd>(this->window_surface_ptr_, file_path.c_str()));
    }
}

void ground::add_character_at_pos(const std::string& file_path, int xPos, int yPos)
{
    if (file_path == "media/sheep.png") {
        characters.push_back(std::make_shared<sheep>(file_path.c_str(), this->window_surface_ptr_, this, xPos, yPos));
    }
    else if (file_path == "media/wolf.png") {
        characters.push_back(std::make_shared<wolf>(file_path.c_str(), this->window_surface_ptr_, this, xPos, yPos));
    }
    else if (file_path == "media/doggo.png") {
        characters.push_back(std::make_shared<shepherd_dog>(file_path.c_str(), this->window_surface_ptr_, this, xPos, yPos));
        std::cout << "doggo" << std::endl;
    }
    else if (file_path == "media/shepherd.png") {
        characters.push_back(std::make_shared<shepherd>(this->window_surface_ptr_, file_path.c_str(), xPos, yPos));
        std::cout << "shepherd" << std::endl;
    }
}

void ground::update()
{
    const unsigned n_animals = characters.size();
    for (unsigned i = 0; i < n_animals; i++)
    {
        characters[i]->move();
        characters[i]->draw();
    }
}

std::vector<std::shared_ptr<moving_object>>& ground::get_characters() {
    return this->characters;
}