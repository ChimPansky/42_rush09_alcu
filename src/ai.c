
#include "alcu.h"
#include <fcntl.h>
#include <unistd.h>
#include "./utils/utils.h"
#include <stdio.h>

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
		return (num);
	return (game->board.heaps[game->board.size - 1]);
}

int	calc_last_row(t_game *game)
{
	if (game->board.heaps[0] == 1 || game->board.heaps[0] == 2 || game->board.heaps[0] == 5)
		return (1);
	else if (game->board.heaps[0] == 3)
		return (2);
	else if (game->board.heaps[0] == 4)
		return (3);
	else
	{
		if ((game->board.heaps[0] - 5) % 4 == 0)
			return (ft_random(game));
		else if ((game->board.heaps[0] - 5) % 4 == 1)
			return (1);
		else if ((game->board.heaps[0] - 5) % 4 == 2)
			return (2);
		else if ((game->board.heaps[0] - 5) % 4 == 3)
			return (3);
	}
	return (-1);
}

int	calc_row(t_game *game, int row, int change)
{
	if ((change == 0 && game->board.heaps[row] > 3) || (change == 1 && game->board.heaps[row] <= 3))
	{
		if (game->board.heaps[row] == 1 || game->board.heaps[row] == 2 || game->board.heaps[row] == 5)
			return (1);
		else if (game->board.heaps[row] == 3)
			return (2);
		else if (game->board.heaps[row] == 4)
			return (3);
		else
		{
			if ((game->board.heaps[row] - 5) % 4 == 0)
				return (ft_random(game));
			else if ((game->board.heaps[row] - 5) % 4 == 1)
				return (1);
			else if ((game->board.heaps[row] - 5) % 4 == 2)
				return (2);
			else if ((game->board.heaps[row] - 5) % 4 == 3)
				return (3);
		}
	}
	else
	{
		if (game->board.heaps[row] == 1 || game->board.heaps[row] == 4)
			return (1);
		else if (game->board.heaps[row] == 2)
			return (2);
		else if (game->board.heaps[row] == 3)
			return (3);
		else
		{
			if ((game->board.heaps[row]) % 4 == 0)
				return (ft_random(game));
			else if ((game->board.heaps[row]) % 4 == 1)
				return (1);
			else if ((game->board.heaps[row]) % 4 == 2)
				return (2);
			else if ((game->board.heaps[row]) % 4 == 3)
				return (3);
		}
	}
	printf("Error\n");
	return (-1);
}

void last_row_moves(int *calc_ideal_moves, t_game *game) // for ai
{
	if (game->board.heaps[0] == 1 || game->board.heaps[0] == 5)
		*calc_ideal_moves += 0;
	else if (game->board.heaps[0] == 2 || game->board.heaps[0] == 3 || game->board.heaps[0] == 4)
		*calc_ideal_moves += 1;
	else
	{
		if ((game->board.heaps[0] - 5) % 4 == 0)
			*calc_ideal_moves += 0;
		else
			*calc_ideal_moves += 1;
	}
}

void	normal_row_moves(int *calc_ideal_moves, t_game *game, int row)
{
	if (game->board.heaps[row] == 1 || game->board.heaps[row] == 2 || game->board.heaps[row] == 3 )
		*calc_ideal_moves += 1;
	else if (game->board.heaps[row] == 4 || game->board.heaps[row] == 5)
		*calc_ideal_moves += 0;
	else
	{
		if ((game->board.heaps[row] - 5) % 4 == 0)
			*calc_ideal_moves += 0;
		else
			*calc_ideal_moves += 1;
	}
}

int calc_ideal_moves(t_game *game)
{
	int calc_ideal_moves = 0;
	int num = 0;

	last_row_moves(&calc_ideal_moves, game);
	for (size_t row = 1; row < game->board.size - 1; row++)
	{
		if (game->board.heaps[row] == 0)
			break;
		normal_row_moves(&calc_ideal_moves, game, row);
	}
	printf("calc_ideal_moves: %d\n", calc_ideal_moves);
	if (calc_ideal_moves % 2 == 0)
	{
		num = calc_row(game, game->board.size - 1, 0);
		printf("Ai on the right way. %d\n", num);
	}
	else
	{
		printf("Ai on the wrong way\n");
		num = calc_row(game, game->board.size - 1, 1);
	}
	return (num);
}

int	calculate(t_game *game)
{
	int	num = -1;

	if  (game->board.size == 1)
	{
		num = calc_last_row(game);
	}
	else
	{
		num = calc_ideal_moves(game);
	}
	return (num);
}

int	ai(t_game *game)
{
	int num;

	num = calculate(game);
	if (num > 0)
	{
		ft_putstr_fd(1, "AI took ");
		ft_putnbr_fd(1, num);
		ft_putstr_fd(1, "\n");
	}
	return (num);
}


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