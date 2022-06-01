// Standard library headers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <dirent.h>

// Custom headers for the project.
#include "io.h"
#include "game-components.h"
#include "first-task.h"

// Macro constants used in this compilation unit.
#define OUTPUT_FORMAT "-output-"
#define SEED_LENGTH_BUFFER 8
#define PATH_TO_INPUT_DIRECTORY "input"


// Prototypes of static methods.
static long _convert_string_to_int(char * string);
static char * _read_seed(FILE * input_file);
static char * _retrieve_index_number(char * filename);

// Static methods implementations.
static char * _retrieve_index_number(char *filename){
    /**
    * @param filename; a string indicating the name of the file.
    *
    * This method returns the index number which is collated at the end of the file name and is preceded by a hyphen.
    *
    * @author Andrei-Paul Ionescu.
    */

    // Check to see whether the input is valid or not.
    assert(filename);

    long number_of_hyphens = 0; 
    char * current = filename;

    while(*current != '\0'){

        if(number_of_hyphens == 2) // Return the substring containing the number.
            return current;

        if(*current == '-')
            ++number_of_hyphens;

        current += sizeof(char);
    }

    // If something went wrong simply attach the postfix O;
    return "O";
}

static long _convert_string_to_int(char * string){
    /**
    * @param string; a given null terminated string object.
    * 
    * This method converts a string object into a long object.
    *
    * @author Andrei-Paul Ionescu.
    */

    // Determine whether the argument is valid.
    assert(string);

    // Temporary variables.
    long pow = 1;
    long long result = 0;

    // A pointer used to navigate thru the memory.
    char * current = string;

    while(*current != '\0'){

        if(!isdigit(*current)) return -1; // The input is erroneous.
        
        result = result * pow + (*current - '0');

        current += sizeof(char);
        pow *= 10;
    } 

    if(result == 0) return -1;
    else return result;
}

static char * _read_seed(FILE * input_file){
    /**
    * @param input_file; the file containing the seed which the program requires.
    *
    * This here helper method reads the seed, trims and cleans the input and yields it back to the caller.
    *
    * @author Andrei-Paul Ionescu
    */

    // Check for the validity of the input.
    assert(input_file);

    // Create a new pointer which points to a memory zone which is big enough to hold the maximal number.
    char * seed = malloc(sizeof(char) * SEED_LENGTH_BUFFER);

    // Check to see if any errrors occurred whilst reserving the memory for the seed variable.
    if(seed == NULL) return NULL; // The user has to determine how it responds to the error.

    long c, i;
    // Reads characters until we either stumbled upon a newline, a blank, or we reached the EOF indicator.
    for(i = 0 ; i < SEED_LENGTH_BUFFER - 1 && (c=fgetc(input_file)) != EOF && c != '\n' && c != ' '; ++i){

         seed[i] = c;
    }
       
    // Collate the null character to the string.
    seed[i] = '\0';

    // Finally return the value to the caller.
    return seed;
}

// Externs methods implementations.
extern void read_and_respond_to_all_input_files(){
    /**
    * @param void; this method takes no formal arguments upon entry.
    *
    * Read the contents of a specific file whose path is defined within a macro constant and take action in accordance to the prefix of the file.
    *
    * @author Andrei-Paul Ionescu
    */

    // Initialise all the required variables.
    DIR *curernt_directory;
    struct dirent *current_dirent_object;
    FILE *currently_selected_file;

    // Open the currently specified directory.
    curernt_directory = opendir(PATH_TO_INPUT_DIRECTORY);
    
    // Check to see whether the operation was successful or not.
    if(curernt_directory == NULL){

        printf("[!] The directory which you tried to open might not exist or the given path is incorrect.\n");
        exit(1);
    }

    // Process each entry which is found within the directory.
    while((current_dirent_object = readdir(curernt_directory)) != NULL){

        // Based on the files prefix determine which tests need to be run on that particular file.
        if(strstr(current_dirent_object->d_name, "q1")){

            printf("[%s]\n", current_dirent_object->d_name);

            // Make local copies of the length of the strings so as to save a bit of time.
            long length_path_to_input_directory = strlen(PATH_TO_INPUT_DIRECTORY);
            long length_current_file_name = strlen(current_dirent_object->d_name);

            // Create a relative path to the location of the current targetted file and pass it to the solve_first_task method.
            char * location_of_current_job = malloc(sizeof(char) * (length_path_to_input_directory + length_current_file_name + 2));

            strcpy(location_of_current_job, PATH_TO_INPUT_DIRECTORY);
            strcpy(location_of_current_job + length_path_to_input_directory, "/");
            strcpy(length_current_file_name + length_path_to_input_directory + 1, current_dirent_object->d_name);
            strcpy(length_current_file_name + length_path_to_input_directory + length_current_file_name + 2, '\0');

            FILE *temporary = fopen(location_of_current_job, 'r');

            if(temporary == NULL){

                // If the file could not be opened then print a silent error message in the terminal and continue the execution of the program.
                printf("[!] The file %s could not be opened.\n", current_dirent_object->d_name);
            } else solve_first_task(temporary, _retrieve_index_number(current_dirent_object->d_name));
        }
            

    }

    // Close the directory.
    closedir(current_dirent_object);
}

extern void print_board(FILE * stream){
    /**
    * @param stream; a file which indicates where the output of this function should be redirected to.
    * 
    * Print the board to the specified outstream.
    *
    * @author Andrei-Paul Ionescu
    */

    // Make sure that the given stream is valid.
    assert(stream);

    // Retrieve a reference to the current board.
    long ** current_board = retrieve_board();

    // Check to see whether a valid reference was received or not.
    if(current_board == NULL){

        printf("[*]There is an error with accessing your board!\n");
        exit(1);
    }

    for(long i = 0 ; i < NUMBER_OF_ROWS ; ++i){
        for(long j = 0 ; j < NUMBER_OF_COLUMNS ; ++j){

            if(current_board[i][j] == 0)
                fprintf(stream, "- ");
            else 
                fprintf(stream, "%ld ", current_board[i][j]);
        }

        fprintf(stream, "\n");
    }
    
    // Liberate the pointer.
    //free(current_board);
}
extern int read_seed(FILE * input_file){
    /**
    * @param input_file; the file containing the seed which the program ought to use so as to generate the sequence.
    *
    * This here method reads a seed from within a specified input file and yields it back to the caller.
    *
    * @author Andrei-Paul Ionescu
    */
    // Determine whether the given file is valid or not.
    assert(input_file);

    // Read the first line which according to the specifications contains the seed and then convert the string object into a long long integer.
    char * seed_in_string_format = _read_seed(input_file);

    if(seed_in_string_format == NULL){

        // Print an error message on the standard output and quit the program.
        fprintf(stdout, "The file you are trying to open does not comply to the specifications or it is corrupted please check for its validity or try inputing another file.");
        exit(1);
    }

    return _convert_string_to_int(seed_in_string_format);
}

FILE * create_output_file(const char * task_id, const char * index_number){
    /**
    * @param task_id; a string object which indicates the prefix of the output file.
    * @param index_number; a string containing the number of the current text.
    *
    * Create a file object which is named after the following convention, task_id-output-o. 
    *
    * @author Andrei-Paul Ionescu
    */

    /// TODO: Deal with the test number.

    // Make sure no errors occurred when transmitting the data and that the user is using the method according to specifications. 
    assert(task_id);

    // Create the name of the output file.
    long length_of_prefix = strlen(task_id);
    long length_of_format = strlen(OUTPUT_FORMAT);
    long length_of_index_number =  strlen(index_number);

    char * filename = malloc(sizeof(char) * (length_of_prefix + length_of_format+ + length_of_index_number + 1));

    strcpy(filename, task_id);
    strcpy(filename + length_of_prefix, OUTPUT_FORMAT);
    strcpy(filename + (length_of_prefix + length_of_format), index_number);
    strcpy(filename + (length_of_prefix + length_of_format + length_of_index_number), "\0");

    // Create a new file object which is identified by the previously created string literal.
    FILE * output = fopen(filename, "w");

    // If any errors occurred whilst creating the file handle them appropriately.
    if(output == NULL) abort();

    return output;
}