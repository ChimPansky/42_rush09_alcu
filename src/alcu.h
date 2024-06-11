#ifndef ALCU_H
# define ALCU_H

# define SYS_ERROR_GNL		"System Error: Cannot read input!\n"
# define SYS_ERROR_MALLOC 	"System Error: Cannot allocate memory!\n"
# define ERROR_ARGUMENTS 	"Error: Invalid program arguments!\n"
# define ERROR_INPUT_FILE 	"Error opening input file!\n"
# define ERROR_BOARD 		"Error: Invalid Board!\n"
# define ERROR_READ_HEAPS 	"Error: Enter a number between 1 and 10000\n"

typedef unsigned long size_t;

enum	e_game_status {
	PLAYING,
	WON,
	LOST
};

typedef struct s_board {
	int		*board;
	size_t	size;
}			t_board;

typedef struct s_game {
	int	game_status;
	t_board	board;
	size_t	round;
}			t_game;

// board_create.c:
int		read_board(t_board *board, int ac, char** av);
void	destroy_board(t_board *board);

// moves.c:
int		player_move(t_game *game);
void	computer_move(t_game *game);

// board_logic.c:


#endif
