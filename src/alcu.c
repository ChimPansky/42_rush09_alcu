// allowed functions:
// read
// write
// open
// close
// malloc
// free
#include "alcu.h"
#include "utils/utils.h"
#include <unistd.h>

int main(int ac, char** av) {
	t_game	game = {0};

	if (read_board(&game.board, ac, av) != SUCCESS)
		return (FAILURE);
	ft_putstr_fd(STDOUT_FILENO, "Game starts!\n");
	while (game.game_status == PLAYING)
	{
		game.round++;
		if (player_move(&game) != SUCCESS)
			return (destroy_board(&game.board), FAILURE);
		computer_move(&game);
	}
	destroy_board(&game.board);
	return (SUCCESS);
}
