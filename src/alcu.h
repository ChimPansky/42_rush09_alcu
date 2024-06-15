#ifndef ALCU_H
# define ALCU_H

#include <stdbool.h>
#include "./get_next_line/get_next_line.h"

# define SYS_ERROR_GNL		"Error\nSystem Error: Cannot read input!\n"
# define SYS_ERROR_MALLOC 	"Error\nSystem Error: Cannot allocate memory!\n"
# define ERROR_ARGUMENTS 	"Error\nInvalid program arguments!\n"
# define ERROR_INPUT_FILE 	"Error\nCannot open input file!\n"
# define ERROR_BOARD 		"Error\nInvalid Board!\n"
# define ERROR_READ_HEAPS 	"Error\nEnter a number between 1 and 10000\n"
# define ERROR_INVALID_MOVE	"Error\nInvalid Move!\n"

# define BOARD_DEFAULT_CAPACITY 50

typedef unsigned long size_t;

enum	e_game_status {
	PLAYING,
	WON,
	LOST,
	ERROR
};

typedef struct s_board {
	int		*heaps;
	int		max_width;
	size_t	size;
	size_t	capacity;
}			t_board;

typedef struct s_game {
	int	game_status;
	t_board	board;
	size_t	round;
	bool	player_turn;
}			t_game;

// ai.c:
int		ai(t_game *game);

// board.c:
int		read_board(t_board *board, int ac, char** av);
void	destroy_board(t_board *board);

// display.c:
void 	display_board(t_board *board);
bool 	update_board(t_board *board, int rm);

// moves.c:
int		player_move(t_game *game);
int		computer_move(t_game *game);
bool	check_game_over(t_game *game);

// validation.c
bool    valid_input(char *input, int *og, int max);

#endif
