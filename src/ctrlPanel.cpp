#include "ctrlPanel.h"

#include "button.h"

#include <iostream>
#include "SDL.h"
// TEST
#include "grid.h"
#include "text.h"

// class attributes from ctrlPanel.h
SDL_Rect ControlPanel::rect;

int ctrlPanelHeight = 200;

extern int winSizeX;
extern int winSizeY;
extern SDL_Renderer *renderer;

// from start.cpp
extern std::string title;

// from text.cpp
extern std::string zig; // ALL FOR TESTING
extern std::string sixtyFour;
extern SDL_Color red;
extern SDL_Color white;

Button b;
Text bText;
Button c;
Text cText;

Text programTitle;
Text credit;

void ControlPanel::showRect() {
    rect.x = 0;
    rect.y = (winSizeY - ctrlPanelHeight);
    rect.w = winSizeX;
    rect.h = ctrlPanelHeight;

    // BUTTONS
    b.create(1400, 900, 270, 70); 
    bText.placeText("+ Seats", sixtyFour, 1413, 918, white, 35);
    c.create(1400, 990, 270, 70);
    cText.placeText("- Seats", sixtyFour, 1413, 1008, white, 35);
    //b.action( Grid::setModifier, 2 );

    //TEXT
    programTitle.placeText(title, sixtyFour, 40, 920, white, 46);
    credit.placeText("Created by: Mr. Robot", sixtyFour, 40, 990, white, 30);
    
    SDL_RenderDrawRect(renderer, &rect);
}