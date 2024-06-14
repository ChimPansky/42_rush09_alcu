#include "alcu.h"
#include "utils/utils.h"
#include "fcntl.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdbool.h>

static	int allocate_board(t_board *board) {
	size_t	new_size;

	if (board->heaps == NULL)
		new_size = BOARD_DEFAULT_CAPACITY;
	else
		new_size = board->capacity + BOARD_DEFAULT_CAPACITY;
	board->heaps = malloc(sizeof(int) * new_size);
	if (!board->heaps)
		return (ft_putstr_fd(STDERR_FILENO, SYS_ERROR_MALLOC), FAILURE);
	return (SUCCESS);
}

static int	grow_board(t_board *board, int new_heap)
{
	int*	tmp_heaps;
	size_t	i;

	tmp_heaps = NULL;
	i = 0;
	if (board->size == board->capacity) {
		tmp_heaps = board->heaps;
		if (allocate_board(board) != SUCCESS)
			return (free(tmp_heaps), FAILURE);
		while (i < board->size) {
			board->heaps[i] = tmp_heaps[i];
			i++;
		}
	}
	board->heaps[i] = new_heap;
	board->size++;
	free(tmp_heaps);
	return (SUCCESS);
}

static int	extract_int_from_line(char *line) {
	(void)line;
	// TODO: read val between 1 and 10000 from line and return it
	if (false)
		return (-1);
	return (5);
}

static int	read_board_from_fd(t_board *board, int fd) {
	char*	line;
	int		gnl_error;
	int		new_heap;

	if (allocate_board(board) != SUCCESS)
		return (FAILURE);
	gnl_error = 0;
	if (fd == STDIN_FILENO)
		ft_putstr_fd(STDOUT_FILENO, "Enter values between 1 and 10000:\n");
	line = get_next_line(fd, &gnl_error);
	new_heap = 0;
	while (line) {
		new_heap = extract_int_from_line(line);
		if (new_heap < 0) {
			ft_putstr_fd(STDERR_FILENO, ERROR_READ_HEAPS);
			free(line);
			line = get_next_line(fd, &gnl_error);
			continue;
		}
		if (grow_board(board, new_heap) != SUCCESS)
			return (destroy_board(board), FAILURE);
		board->size++;
		free(line);
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
	free(board->heaps);
}
