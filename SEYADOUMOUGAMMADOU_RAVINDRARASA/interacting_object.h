#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include <set>

class interacting_object {

public:
	interacting_object();

	~interacting_object();

	std::string getProprety(std::string key);

	void setProprety(std::string key, std::string value);
	void insertProprety(std::string key, std::string value);

	// geteur pour obtenir l'attribut _properties 
	std::map<std::string, std::string>& getProperties();

private:
	std::map<std::string, std::string> _properties;
};