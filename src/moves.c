#include "alcu.h"
#include "utils/utils.h"
#include <unistd.h>
#include <stdbool.h>

// static int	take_matches(t_board *board, int amount) {
// 	int	*last_heap_size;

// 	last_heap_size = &board->heaps[board->size - 1];

// 	if (*last_heap_size < amount)
// 		return (ft_putstr_fd(STDERR_FILENO, ERROR_INVALID_MOVE), FAILURE);
// 	*last_heap_size -= amount;
// 	return (SUCCESS);
// }

// static bool	check_game_over(t_game *game) {
// 	(void)game;
// 	return (false);
// }

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
