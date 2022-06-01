// Standard library headers. 
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Custom headers for the project.
#include "game-components.h"
#include "io.h"

// Prototypes of static method of the compilation unit.

// Symbolic constants of the file.

// Main method of the software.
int main(void){

    initialise_board();
    print_board(stdout);
    return EXIT_SUCCESS;
}