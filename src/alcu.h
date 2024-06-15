#ifndef ALCU_H
# define ALCU_H

#include <stdbool.h>

# define SYS_ERROR_GNL		"System Error: Cannot read input!\n"
# define SYS_ERROR_MALLOC 	"System Error: Cannot allocate memory!\n"
# define ERROR_ARGUMENTS 	"Error: Invalid program arguments!\n"
# define ERROR_INPUT_FILE 	"Error opening input file!\n"
# define ERROR_BOARD 		"Error: Invalid Board!\n"
# define ERROR_READ_HEAPS 	"Error: Enter a number between 1 and 10000\n"
# define ERROR_INVALID_MOVE	"Error: Invalid Move!\n"


# define BOARD_DEFAULT_CAPACITY 10


typedef unsigned long size_t;

enum	e_game_status {
	PLAYING,	// game in progress...
	WON,		// player won
	LOST		// AI won
};

typedef struct s_board {
	int		*heaps;
	int		max_width;		// longest row(heap) in the board
	size_t	size;			// number of rows(heaps) - matches will always be removed from heaps[size - 1]
	size_t	capacity;		// this is for mem alloc...
}			t_board;

typedef struct s_game {
	int	game_status;
	t_board	board;
	size_t	round;			// start with 0 and increase at the beginning of each round
	bool	player_turn;	// is it the players turn or the AI's turn? (start with false)
}			t_game;

// board.c:
int		read_board(t_board *board, int ac, char** av);
void	destroy_board(t_board *board);

// moves.c:
int		player_move(t_game *game);
void	computer_move(t_game *game);


#endif
