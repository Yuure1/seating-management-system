#include "grid.h"

#include <iostream>
#include "SDL.h" // for rect
#include <math.h> // for fmod
#include <vector> // for list

int Grid::modifier = 1; // default value

bool isCreated = false;

//#include "start.h" // header or else "multiple definition error"
extern int winSizeX; // vars from start.cpp
extern int winSizeY;

// from start.cpp
extern SDL_Renderer *renderer; // to render with draw()
extern SDL_Event event;
extern int ctrlPanelH;

// from mouse.cpp
extern SDL_Point mousePos;

std::vector<int> factors;

// vars for grid status
int null = 0;
int created = 1;
int empty = 2;
int occupied = 3;

void Grid::build(int xPos, int yPos, int area) { // pseudo-constructor
    rect.x = xPos;
    rect.y = yPos;
    rect.w = area;
    rect.h = area;
    isCreated = false;
    isEmpty = false;
};

bool checkForRemainder(int dividend, int divisor) { 
    double quotient;
    double remainder;

    quotient = static_cast<double>(dividend) / divisor; // cast to perform double division
    remainder = fmod(quotient, 1); // check for remainder by performing mod 1

    bool result = (remainder > 0) ? true : false; // return true if remainder has value or else false
    return result;
}

// pushing elements to vector 'factors'
void getCommonFactors(int num1, int num2) {
    int lowerNum = std::min(num1, num2);

    // OPTIONAL DISPLAY
    //std::cout << num1 << ", " << num2 << "\n"; 

    for(int i=2; i<=(lowerNum/2); ++i) { // start dividing from 2 up until half of the lowerNumber
        if( !checkForRemainder(num1, i) && !checkForRemainder(num2, i) ) { // if both no remainder
            factors.push_back(i); // add to factors vector if it is common
        } else { continue; }
    }

    // OPTIONAL DISPLAY
    for(int e : factors) {
        std::cout << e << ", ";
    }

    std::cout << "\n";
}

bool modChanged = true; // modifier value has been changed
std::vector<Grid> unit;

void Grid::draw() { 
    if(modChanged) {
        std::cout << "mod changed to: " << modifier << "\n"; // debug msg

        int i = factors.size() - modifier;
        int r = (winSizeY - ctrlPanelH) / factors[i];
        int c = winSizeX / factors[i];

        std::cout << c << ", " << r << "\n";

        // CREATE OBJECTS
        for(int j=0; j<r; ++j) {
            for(int k=0; k<c; ++k) {
                Grid g;
                g.build( (k * factors[i]), (j * factors[i]), factors[i] );

                unit.push_back(g);
                SDL_RenderDrawRect(renderer, &g.rect); // OPTIONAL DISPLAY
                // use images to create borders for grid units

            } // nested for
        } // outer for 

        modChanged = false;
    } 
} // end of draw

void Grid::action() {
    // CHECK IF MOUSE IS HOVERING OVER UNITS
    for(int i=0; i<unit.size(); ++i) {
        if( SDL_PointInRect(&mousePos, &unit[i].rect) ) {
            // IF CLICKED
            if( event.type == SDL_MOUSEBUTTONDOWN ) {
                // IF RIGHT BUTTON
                if( event.button.button == SDL_BUTTON_RIGHT ) {
                    if(!unit[i].isCreated) {
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer, &unit[i].rect);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &unit[i].rect);

                        unit[i].isCreated = true;
                    } else {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer, &unit[i].rect);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &unit[i].rect);

                        unit[i].isCreated = false;
                    }
                } else if( event.button.button == SDL_BUTTON_LEFT ) {
                    if(unit[i].isCreated && !unit[i].isEmpty) {
                        SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer, &unit[i].rect);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &unit[i].rect);
                        std::cout << "unit is set to empty" << "\n";

                        unit[i].isEmpty = true;
                    } else if(unit[i].isCreated && unit[i].isEmpty) {
                        SDL_SetRenderDrawColor(renderer, 120, 120, 120, SDL_ALPHA_OPAQUE);
                        SDL_RenderFillRect(renderer, &unit[i].rect);
                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_RenderDrawRect(renderer, &unit[i].rect);

                        unit[i].isEmpty = false;
                    } 
                }
            }
        } // outer if
    } // end of for
}

// mutator and accessor methods
void Grid::setModifier(int val) { 
    modifier = val; 
    modChanged = true;
} // can i access normally after defining(?)
int Grid::getModifier() { return modifier; }