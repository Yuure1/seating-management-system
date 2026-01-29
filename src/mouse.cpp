#include "mouse.h"

#include <iostream> // for cout
#include "SDL.h" // for sdl point

SDL_Point mousePos; // use extern to use in other source file

void Mouse::getPos() {
    SDL_GetMouseState(&mousePos.x, &mousePos.y); // gives value to point's .x and .y
    //std::cout << mousePos.x << ", " << mousePos.y << "\n";
}