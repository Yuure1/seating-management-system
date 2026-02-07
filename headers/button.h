#pragma once

#include <iostream>
#include "SDL.h"

extern SDL_Point mousePos;
extern SDL_Event event;

class Button {
private:
    int x;
    int y;
    int w;
    int h;
    SDL_Rect rect;
public:
    void create(int x, int y, int w, int h); // pseudo-constructor

    // VARIADIC FUNCTION IMPLEMENTATION
    template<typename F, typename... A>
    void action(F func, A... args) {
        if( SDL_PointInRect(&mousePos, &rect) ) {
        //std::cout << "mouse is hovering above me" << "\n";

            if( event.type == SDL_MOUSEBUTTONDOWN ) {
                if( event.button.button == SDL_BUTTON_LEFT ) {
                    func(args...);
                }
            }
        }
    }
    // VARIADIC FUNCTION IMPLEMENTATION

};