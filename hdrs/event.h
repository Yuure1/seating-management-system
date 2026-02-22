#pragma once

#include "SDL.h"

class Event {
private:
    static SDL_Event event;
public:
    static void loop();
    static void initStuff();
};