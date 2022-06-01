// Standard library headers. 
#include <stdlib.h>
#include <assert.h>

// Custom headers for the project.
#include "game-components.h"

// Prototypes of static method of the compilation unit.


// Global variables utilised within the compilation unit.
long board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
// Implemenation of static methods.

// Implemenations of external methods belonging to the header of the compilation unit.
long ** retrieve_board(void){
    /**
    * @param void; this method does not require any parameters.
    *
    * Return a pointer to the caller which point him or her towards the place in memory where the board is stored.
    *
    */

    return (long**) board;
}
extern void initialise_board(void){
    /**
    * @param void; this method does not require any parameters.
    *
    * Initialise the current instance of the board where the size of the board are defined in the symbolic constant which are to be found within this 
    * compilation unit.
    *
    * @author Andrei-Paul Ionescu.
    */

    for(int i = 0 ; i < NUMBER_OF_ROWS ; ++i){
        for(int j = 0 ; j < NUMBER_OF_COLUMNS ; ++j)
            board[i][j] = 1;
    }
    
}