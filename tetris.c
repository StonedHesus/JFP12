// Standard library headers. 
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Custom headers for the project.
#include "game-components.h"
#include "io.h"
#include "second-task.h"

// Prototypes of static method of the compilation unit.

// Symbolic constants of the file.

// Main method of the software.
int main(void){

    print_game_title();
    initialise_board();
    print_board(stdout);
    place_piece(1, 7, 2, 2);
    print_board(stdout);
    return EXIT_SUCCESS;
}
