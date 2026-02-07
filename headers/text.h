#pragma once

#include <iostream> // for string arg
#include "SDL.h"

class Text {
private:
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    SDL_Color color;
    SDL_Rect rect;
public:
    static void fontInit();
    void placeText(std::string msg, std::string fontPath, int xPos, int yPos, SDL_Color color, int size);
};