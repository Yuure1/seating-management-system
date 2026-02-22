#include "event.h" // class header

#include <iostream>
#include "window.h"

SDL_Event Event::event;
bool stuffLoaded = false;

void Event::loop() {
    // one-time events
    Event::initStuff();
    // end of one-time events

    while(true) {
        if(SDL_PollEvent(&event)) { // return 1 if there is a pending event
            SDL_RenderPresent(Window::getRenderer());

            if(event.type == SDL_QUIT) { // if user presses x button
                SDL_DestroyWindow(Window::getWindow());
            }
        }
    } // end of while
}

void Event::initStuff() {
    if(!stuffLoaded) {
        std::cout << "Initializing stuff..." << '\n';
        Window::init();

        stuffLoaded = true;
        std::cout << "" << '\n';

        // only make program run if all libraries initialized successfully
    }
}