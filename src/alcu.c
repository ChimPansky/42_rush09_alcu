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
	display_board(&game.board);
	while (game.game_status == PLAYING)
	{
		game.round++;
		computer_move(&game);
		if (check_game_over(&game))
			continue;
		display_board(&game.board);
		if (player_move(&game) != SUCCESS)
			return (destroy_board(&game.board), FAILURE);
		check_game_over(&game);
		display_board(&game.board);
	}
	if (game.game_status == WON)
		ft_putstr_fd(STDOUT_FILENO, "Yow Won :)\n");
	else
		ft_putstr_fd(STDOUT_FILENO, "DESTROYER II has destroyed you :( \n");
	destroy_board(&game.board);
	return (SUCCESS);
}
