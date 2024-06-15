
#include "alcu.h"
#include <fcntl.h>
#include <unistd.h>
#include "./utils/utils.h"

// Creates a random number between 1 and 3
int	ft_random(t_game *game)
{
	int	num;
	int	fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, "Error: Cannot open /dev/random\n");
		return (-1);
	}
	if (read(fd, &num, 1) < 0)
	{
		ft_putstr_fd(2, "Error: Cannot read /dev/random\n");
		close(fd);
		return (-1);
	}
	close(fd);
	if (num < 0)
		num *= -1;
	num = num % 3 + 1;
	if (num <= game->board.heaps[game->board.size - 1])
		game->board.heaps[game->board.size - 1] -= num;
	else
		game->board.heaps[game->board.size - 1] = 0;
	return (0);
}

int	ft_calc_last_row(t_game *game)
{
	if (game->board.heaps[0] == 1)
	{
		game->board.heaps[0] = 0;
		ft_putstr_fd(1, "AI took 1\n");
	}
	else if (game->board.heaps[0] == 2)
	{
		game->board.heaps[0] = 1;
		ft_putstr_fd(1, "AI took 1\n");
	}
	else if (game->board.heaps[0] == 3)
	{
		game->board.heaps[0] = 1;
		ft_putstr_fd(1, "AI took 2\n");
	}
	else if (game->board.heaps[0] == 4)
	{
		game->board.heaps[0] = 1;
		ft_putstr_fd(1, "AI took 3\n");
	}
	else if (game->board.heaps[0] == 5)
	{
		game->board.heaps[0] = 4;
		ft_putstr_fd(1, "AI took 1\n");
	}
	else
	{
		if ((game->board.heaps[0] - 5) % 4 == 0)
			ft_random(game);
		else if ((game->board.heaps[0] - 5) % 4 == 1)
		{
			game->board.heaps[0] -= 1;
			ft_putstr_fd(1, "AI took 1\n");
		}
		else if ((game->board.heaps[0] - 5) % 4 == 2)
		{
			game->board.heaps[0] -= 2;
			ft_putstr_fd(1, "AI took 2\n");
		}
		else if ((game->board.heaps[0] - 5) % 4 == 3)
		{
			game->board.heaps[0] -= 3;
			ft_putstr_fd(1, "AI took 3\n");
		}
	}
	return (0);
}

int	ft_calculate(t_game *game)
{
	if  (game->board.size == 1)
	{
		ft_calc_last_row(game);
	}
	return (0);
}

int	ai(t_game *game)
{
	// The computer starts playing
	// goal: leave the player with 1 heap

	if (game->board.size > 1)
	{
		if (ft_random(game))
			return (1);
	}
	else
	{
		if (ft_calculate(game))
			return (1);
	}
	return (0);
}

// #include <stdio.h>
// int main (void)
// {
// 	t_game game;
// 	t_board board;
// 	char str[2];

// 	game.board = board;
// 	game.board.size = 1;
// 	game.board.heaps[0] = 17;
// 	printf("%d\n", game.board.heaps[0]);
// 	while (game.board.heaps[0] > 0)
// 	{
// 		ai(&game);
// 		printf("%d\n", game.board.heaps[0]);
// 		read(0, str, 2);
// 		game.board.heaps[0] -= str[0] - '0';
// 		printf("%d\n", game.board.heaps[0]);
// 	}
// 	return (0);
// }