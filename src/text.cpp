#include "text.h"

#include <iostream>

#include "SDL_ttf.h"

// FONT PATHS
std::string zig = "media/fonts/zig_____.ttf";
std::string sixtyFour = "media/fonts/Sixtyfour-Regular-VariableFont_BLED,SCAN.ttf";

TTF_Font *text = NULL;

SDL_Color red = { 255, 0, 0 };
SDL_Color white = { 255, 255, 255 };

// from start.cpp
extern SDL_Renderer *renderer;

void Text::fontInit() {
    if(TTF_Init() < 0) {
        std::cout << "Font: " << SDL_GetError() << "\n"; // debug msg
    } else {
        std::cout << "Font: OK" << "\n"; // debug msg
    }

    // TTF_Init();
}

void Text::placeText(std::string msg, std::string fontPath, int xPos, int yPos, SDL_Color color, int size) { // this will only be called once inside grid
    int w;
    int h;
    
    text = TTF_OpenFont(fontPath.c_str(), size); // second argument is font point size
    surface = TTF_RenderText_Solid(text, msg.c_str(), color); // return value is surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h); // get texture info like width and height

    rect.x = xPos;
    rect.y = yPos;
    rect.w = w;
    rect.h = h;

    std::cout << msg << rect.w << "\n";

    SDL_RenderCopy(renderer, texture, NULL, &rect);
}