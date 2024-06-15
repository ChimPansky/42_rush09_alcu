#include "alcu.h"
#include "utils/utils.h"
#include <unistd.h>
#include <stdbool.h>

bool	check_game_over(t_game *game) {
	if (game->board.size < 1) {
		if (game->player_turn)
			game->game_status = WON;
		else
			game->game_status = LOST;
		return (true);
	}
	return (false);
}

int		player_move(t_game *game)
{
	char 	*input;
	int		num;
	int		error;
	
	ft_putstr_fd(STDOUT_FILENO, "PLAYER MOVING...\n");
	take_input:
	input = get_next_line(0, &error);
	if (!input)
		goto take_input;
	num = ft_atoi(input); //need to work on validation
	update_board(&game->board, num);
	//write(1, "\n", 1);
	game->player_turn = false;
	return (SUCCESS);
}

void	computer_move(t_game *game)
{
	ft_putstr_fd(STDOUT_FILENO, "COMPUTER MOVING...\n");
	update_board(&game->board, ai(game));
	game->player_turn = true;
}
