#include "alcu.h"
#include "utils/utils.h"
#include "fcntl.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>

static int	grow_board(t_board *board, char *line)
{
	(void)board;
	(void)line;
	return (SUCCESS);
}

static int	read_board_from_fd(t_board *board, int fd) {
	char*	line;
	int		gnl_error;

	gnl_error = 0;
	line = get_next_line(fd, &gnl_error);
	while (line) {
		if (grow_board(board, line) != SUCCESS)
			return (destroy_board(board), FAILURE);
		board->size++;
		line = get_next_line(fd, &gnl_error);
	}
	if (gnl_error)
		return (destroy_board(board),
			ft_putstr_fd(STDERR_FILENO, SYS_ERROR_GNL), FAILURE);
	if (board->size < 1)
		return (destroy_board(board),
			ft_putstr_fd(STDERR_FILENO, ERROR_BOARD), FAILURE);
	return (SUCCESS);
}

int	read_board(t_board *board, int ac, char** av) {
	int	fd;

	if (ac == 1)
		fd = STDIN_FILENO;
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr_fd(STDERR_FILENO, ERROR_INPUT_FILE), FAILURE);
	}
	else {
		return (ft_putstr_fd(STDERR_FILENO, ERROR_ARGUMENTS)), FAILURE;
	}
	if (read_board_from_fd(board, fd) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

void	destroy_board(t_board* board)
{
	free(board->board);
}
