#ifndef IO_H
#define IO_H 

extern FILE * create_output_file(const char * task_id, const char * index_number);
extern int read_seed(FILE * input_file);
extern void print_board(FILE * stream);

extern void read_and_respond_to_all_input_files(void);

// Methods which deal with the manner in which the game is presented to the user and which manipulate the terminal.
extern void print_game_title();
extern int select_game_mode();

#endif //IO_H
