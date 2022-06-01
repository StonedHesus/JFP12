#ifndef GAME_COMPONENTS_H
#define GAME_COMPONENTS_H 

// Symbolic constants of the file.
#define NUMBER_OF_ROWS 24
#define NUMBER_OF_COLUMNS 12


extern void initialise_board(void);
extern long ** retrieve_board(void);
extern void modify_board(long new_board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]);
extern void destroy_board(void);

extern long ** retrieve_piece(long piece_code, long number_of_rotations);

#endif //GAME_COMPONENTS_H
