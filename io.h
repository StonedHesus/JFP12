#ifndef IO_H
#define IO_H 

extern FILE * create_output_file(const char * task_id, const char * index_number);
extern int read_seed(FILE * input_file);
extern void print_board(FILE * stream);

extern void read_and_respond_to_all_input_files(void);

#endif //IO_H
