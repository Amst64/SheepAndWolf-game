// SDL_Test.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include "animal.h"

// Defintions
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 600; // Height of window in pixel
constexpr unsigned animal_perception = 100; // rayon de perception des animaux 
constexpr unsigned death_time = 10050; // rayon de perception des animaux 

// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;

// Helper function to initialize SDL
void init();


// The "ground" on which all the animals live (like the std::vector
// in the zoo example).


// The application class, which is in charge of generating the window
