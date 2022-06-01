// Standard library headers utilised within the compilation unit.
#include <stdio.h>
#include <assert.h>

// Custom headers which belong to the current project but are utilised by this compilation unit.
#include "io.h"
#include "first-task.h"

// Prototypes of static method of the compilation unit.
static long _bit_manipulation_result(long hashed_value);
static long _naive_bit_manipulation_result(long hashed_value);
static long _binary_exponentiation(long long base, long long power);

// Symbolic constants of the file.
#define PREDEFINED_NUMBER_OF_PIECES_IN_A_SEQUENCE 20
#define BITS 32 // The maximum numbers of bits of our integers.

#define TASK_ID "q1"

// Global variables utilised within this compilation unit.
FILE * output = NULL;

// Implemenation of static methods.
static long _bit_manipulation_result(long hashed_value){
    /**
    * @param hashed_value; a long integer.
    *
    * This here method, albeit the confusing number, accomplishes one simple feat, it generates a new number which is created based on the three MSB.
    *
    * @author Andrei-Paul Ionescu
    */

    // Not enough time to implement a good solution...
    return ((hashed_value & 1 << (BITS - 1)) ? 1 : 0) * 2 + ((hashed_value & 1 << (BITS - 2)) ? 1 : 0) * 2+ ((hashed_value & 1 << (BITS - 3)) ? 1 : 0) * 2;
}

static long _naive_bit_manipulation_result(long hashed_value){
    /**
    * @param hashed_value; a long integer.
    *
    * Similar to the _bit_manipulation_result only it does not user bit operations.
    *
    * @author Andrei-Paul Ionescu
    */

    long first = 0, second = 0, third = 0;

    first = hashed_value % 2;
    hashed_value /= 2;

    while(hashed_value){

        
        
        second = first;
        third = second;

        first = hashed_value % 2;
        
        hashed_value /=2;
    }

    return (first  + second + third );
}

static long _binary_exponentiation(long long base, long long power){
    /**
    * @param base; an integer value which represents the base of the exponentiation.
    * @param power; the exponent of the computation.
    *
    * This function implements a binary exponentation algorithm so as to compute the result of the operation of exponentation in O(log(n)) time.

    * @author Andrei-Paul Ionescu.
    */

    // This algorithm is only optimised for positive powers.
    assert(power > - 1);

    long result = 1;
    while(power > 0){

        if(power & 1){

            result *= base;
        }

        base *= base;
        power >>= 1;

    }

    return result;
}

// Implemenations of external methods belonging to the header of the compilation unit.
extern void solve_first_task(FILE *target, char * target_number){
    /**
    * @param target; the currently opened file.
    *
    * Treat the given contained within the values in accordance to the specifications of the current job/task.
    *
    * @author Andrei-Paul Ionescu.
    */

    // Make sure that the reference passed to the method is valid.
    assert(target);

    output = create_output_file(TASK_ID, target_number);

    if(output == NULL) output = stdout;

    generate_sequence_of_pieces(read_seed(target), PREDEFINED_NUMBER_OF_PIECES_IN_A_SEQUENCE);
}

extern long generate_sequence_of_pieces(long given_seed, long number_of_pieces_to_be_generated){
    /**
    * @param given_seed; an integer whose value is comprised in the interval [0, 1000000].
    * @param number_of_pieces_to_be_generated; an integer value which represents how many pieces we ought to generate.
    *
    * Compute number_of_pieces_to_be_generated moevs using the given seed value.
    *
    * @author Andrei-Paul Ionescu
    */

    // Make sure that the given input is strictly positive.
    assert(given_seed > 0 && number_of_pieces_to_be_generated > 0);

    long hash_value = _binary_exponentiation(2, 32);
    long previous_value = given_seed;
    long current_value;

    for(long i = 0 ; i < number_of_pieces_to_be_generated ; ++i){

        current_value = (22695477 * previous_value + 1) % (hash_value);
        previous_value = current_value;
        fprintf(output, "%ld\n", _bit_manipulation_result(current_value));
    
    }

    // Properly close the output file.
    fclose(output);
    return 1;
}