#include "button.h"

#include <iostream>
#include "SDL.h"

#include "mouse.h"

extern SDL_Renderer *renderer; // from start.cpp
extern SDL_Point mousePos;
extern SDL_Event event;

/* void isClicked(F func, A... args) {
    // func(args...); // expand args
} */

/* template<typename F, typename... A> // F - function, A - args
void Button::action(F func, A... args) {
    if( SDL_PointInRect(&mousePos, &rect) ) {
        std::cout << "mouse is hovering above me" << "\n";

        if( event.type == SDL_MOUSEBUTTONDOWN ) {
            if( event.button.button == SDL_BUTTON_LEFT ) {
                func(args...);
            }
        }
    }
} */

void Button::create(int x, int y, int w, int h) { // CONSTRUCTOR DEFINITION
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // put code below this inside action function

    /*
    if( SDL_PointInRect(&mousePos, &rect) ) {
        std::cout << "mouse is hovering above me" << "\n";
    }
        */

    SDL_RenderDrawRect(renderer, &rect);
}