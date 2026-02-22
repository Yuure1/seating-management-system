#include "window.h" // class header

#include "SDL.h"
#include <iostream>

// for setting win size
int wWidth;
int wHeight;
int rRate; // refresh rate
SDL_DisplayMode mode;

// window
SDL_Window* Window::window = NULL;
SDL_Rect Window::winRect;

// renderer
SDL_Renderer* Window::renderer = NULL;
int renderingDriver = -1; // first driver to support requested flags in SDL_CreateRenderer

// file function declarations
void setWinSize();
// end of file function declarations

// class function definitions

// initialize window and renderer
void Window::init() {
    if(SDL_Init(SDL_INIT_VIDEO) == 0) { // on success

        setWinSize(); // set the window size first
        window = SDL_CreateWindow( // create the window
            "test program",
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            wWidth,
            wHeight,
            SDL_WINDOW_SHOWN
        );

        std::cout << "Video initialization success." << '\n';

        // next thing to do is display window without closing immediately

        if(window != NULL) { // on success of window creation
            std::cout << "Window creation success." << '\n';

            // create window rect
            winRect.x = 0;
            winRect.y = 0;
            winRect.w = wWidth;
            winRect.h = wHeight;

            // create renderer
            renderer = SDL_CreateRenderer(
                window, 
                renderingDriver, 
                SDL_RENDERER_ACCELERATED
            );

            if(renderer != NULL) { // on success of renderer creation
                std::cout << "Renderer creation success." << '\n';
            } else {
                std::cout << "Failed to create renderer. Error code: " << SDL_GetError() << '\n';
            }

        } else {
            std::cout << "Failed to create window. Error code: " << SDL_GetError() << '\n';
        }

    } else {
        std::cout << "Failed to initialize SDL Video. Error code: " << SDL_GetError() << '\n';
    }

    // show rect for debugging
    Window::showRects(false); 
} // end of init()

// show rects of all elements
void Window::showRects(bool &&b) {
    if(b) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer, &winRect);
        
        std::cout << "Show window rect: TRUE" << '\n';

    } else {
        std::cout << "Show window rect: FALSE" << '\n';

    }
}

// accessor functions definitions
SDL_Window* Window::getWindow() { return window; }
SDL_Renderer* Window::getRenderer() { return renderer; }

// end of class function definitions

// file function definitions
void setWinSize() {
    if(SDL_GetDesktopDisplayMode(0, &mode) == 0) { // on success
        wWidth = mode.w;
        wHeight = mode.h;

        std::cout << "Window size was successfully set to: " << wWidth << "x" << wHeight << '\n';

    } else {
        std::cout << "Failed to set window size. Error code: " << SDL_GetError() << '\n';

    }
}