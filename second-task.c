// Standard library headers. 
#include <stdlib.h>
#include <assert.h>

// Custom headers for the project.
#include "second-task.h"


// Prototypes of static method of the compilation unit.

// Symbolic constants of the file.

// Implemenation of static methods.

// Implemenations of external methods belonging to the header of the compilation unit.
extern long place_piece(long piece_type, long target_row, long target_column, long number_of_rotations){
    /**
    * @param piece_type; a number between 0 and 7 which indicates the type of piece which is being considered,
    * @param target_row; the row which we are targetting the piece towards.
    * @param target_column; the column to which we are targetting the piece towards.
    * @param number_of_rotations; determine how many time the piece was rotated.
    *
    * This here method is trying to place a piece of type piece_type at coordinates target_row, target_column, taking into consideration the fact that the piece
    * was rotated number_of_rotations time.
    *
    * @author Andrei-Paul Ionescu.
    */

    // Check the validity of the input,
    if(piece_type < 0 || piece_type > 7) return -1; // Erroneous input.
    if(target_row < 0 || target_row > 23) return -1; // Erroneous input.
    if(target_column < 0 || target_column > 11) return -1; // Erroneous input.

    // Retrieve the piece and apply the rotations.

    // Check to see whether the piece fits or not.
} 