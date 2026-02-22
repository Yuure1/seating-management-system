#pragma once

#include "SDL.h" // for SDL_Rect type

class Window {
private:
    // attributes
    static SDL_Window *window;
    static SDL_Rect winRect;
    static SDL_Renderer *renderer;
public:
    // functions
    static void init();
    static void showRects(bool &&b);

    // accessor functions
    static SDL_Window* getWindow();
    static SDL_Renderer* getRenderer();
};