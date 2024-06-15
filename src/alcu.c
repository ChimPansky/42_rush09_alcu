#include "alcu.h"
#include "utils/utils.h"
#include <unistd.h>

int main(int ac, char** av) {
	t_game	game = {0};

	if (read_board(&game.board, ac, av) != SUCCESS)
		return (FAILURE);
	ft_putstr_fd(STDOUT_FILENO, "\nGame starts!\n");
	display_board(&game.board);
	while (game.game_status == PLAYING)
	{
		game.round++;
		if(computer_move(&game))
			return (destroy_board(&game.board), FAILURE);
		if (check_game_over(&game))
			continue;
		display_board(&game.board);
		if (player_move(&game) != SUCCESS)
			return (destroy_board(&game.board), FAILURE);
		if (check_game_over(&game))
			continue;
		display_board(&game.board);
	}
	if (game.game_status == WON)
		ft_putstr_fd(STDOUT_FILENO, "\nYow Won :)\n");
	else if (game.game_status == LOST)
		ft_putstr_fd(STDOUT_FILENO, "\nDESTROYER II has destroyed you :( \n");
	else
	 	ft_putstr_fd(STDERR_FILENO, "\nError\n");
	destroy_board(&game.board);
	return (SUCCESS);
}
