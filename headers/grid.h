#pragma once

#include <iostream>
#include "SDL.h" // for sdlrect

// functions
void getCommonFactors(int num1, int num2);

// class
class Grid {
private:
    static int modifier;
    static bool seatCreated; // for confirmation window
    SDL_Rect rect;
    bool isCreated;
    bool isEmpty;
    /*
    created
    empty
    occupied
    */
public:
    void build(int xPos, int yPos, int area);

    static void draw();
    static void action();
    static void setModifier(int val);
    static int getModifier();
};

/*

*/
