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
	int		error;
	int		num;
	
	error = 0;
	num = 0;
	input = NULL;
	ft_putstr_fd(STDOUT_FILENO, "PLAYER MOVING...\n");
	display_msg:
	ft_putstr_fd(STDOUT_FILENO, "Please enter a number between 1 and 3:\n");
	take_input:
	input = get_next_line(0, &error);
	if (error)
	{
		if (input)
			free(input);
		return (FAILURE);
	}
	if (!input)
		goto take_input;
	if (!valid_input(input, &num))
	{
		free(input);
		goto display_msg;
	}
	if (!update_board(&game->board, num))
	{
		ft_putstr_fd(STDOUT_FILENO, "You cannot take more than available\n");
		free(input);
		goto take_input;
	}
	game->player_turn = false;
	free(input);
	return (SUCCESS);
}

void	computer_move(t_game *game)
{
	ft_putstr_fd(STDOUT_FILENO, "COMPUTER MOVING...\n");
	update_board(&game->board, ai(game));
	game->player_turn = true;
}
