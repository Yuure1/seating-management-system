#include "start.h"

#include "grid.h" // for testing class functions
#include "mouse.h"

#include <iostream> // cout
#include "SDL.h" // window creation
#include "SDL_image.h" // testing

SDL_Window *window = NULL; 
SDL_Renderer *renderer = NULL;
int driver = -1;

SDL_Event event; // my event

SDL_DisplayMode mode;
int monitor = 0;
int winSizeX;
int winSizeY;
int rRate; // refresh rate
int ctrlPanelH = 200; // control panel, 200px height

std::string programName = "Seating Manager ", programVer = "v0.0.0"; 
std::string title = programName + programVer;

void setWinSize() {
    if(SDL_GetDesktopDisplayMode(monitor, &mode) < 0) {
        std::cout << "failed " << SDL_GetError() << "\n";
    } else {
        winSizeX = mode.w;
        winSizeY = mode.h;
        rRate = mode.refresh_rate;
    }
}



// method definitions
void Start::createWindow() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) { // return 0 on success & negative error code on failure
        std::cout << "Video: " << SDL_GetError() << "\n"; // debug msg
    } else {
        std::cout << "Video: OK" << "\n"; // debug msg

        // WINDOW CREATION
        setWinSize();
        window = SDL_CreateWindow(
            title.c_str(), 
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
            winSizeX, winSizeY,
            SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI ); // create window; giving a value to window
            if(window == NULL) { // return NULL on failure
                std::cout << "Window: " << SDL_GetError() << "\n"; // debug msg
            } else {
                std::cout << "Window: OK" << "\n"; // debug msg

                // RENDERER CREATION
                renderer = SDL_CreateRenderer(window, driver, SDL_RENDERER_ACCELERATED);
                if(renderer == NULL) {
                    std::cout << "Renderer: " << SDL_GetError() << "\n"; // debug msg
                } else {
                    std::cout << "Renderer: OK" << "\n"; // debug msg
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                }
            }
    } 
} // end of createWindow

void Start::queueEvent() {
    // functions to only be called once
    getCommonFactors(winSizeX, (winSizeY - ctrlPanelH));

    while(true) {
        SDL_RenderPresent(renderer); // render 

        // functions to be constantly called
        Mouse::getPos();
        Grid::draw();

        if( SDL_PollEvent(&event) ) { // pass mem address of event
            // functions with event variable
            Grid::action();

            if(event.type == SDL_QUIT) { // if user presses x button
                SDL_DestroyWindow(window);
                SDL_Quit();
                break;
            } 
        } // event poll
    } // main while loop
}

// combine multiple boxes - idea ni edward