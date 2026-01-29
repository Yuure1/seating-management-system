#include <iostream>

#include "start.h" // classes imported
#include "grid.h"

int main(int argc, char *argv[]) { // these args are for making the program cross-platform
    Start::createWindow(); // :: scope resolution operator
    Start::queueEvent();

    return 0;
}