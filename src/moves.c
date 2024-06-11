#include "alcu.h"
#include "utils/utils.h"
#include <unistd.h>

int		player_move(t_game *game)
{
	(void) game;
	ft_putstr_fd(STDOUT_FILENO, "PLAYER MOVING...");
	return (SUCCESS);
}

void	computer_move(t_game *game)
{
	ft_putstr_fd(STDOUT_FILENO, "COMPUTER MOVING...");
	if (game->round > 10)
		game->game_status = LOST;
}
