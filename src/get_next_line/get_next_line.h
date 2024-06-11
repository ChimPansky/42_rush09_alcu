#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

typedef struct s_buffer
{
	char	str[BUFFER_SIZE + 1];
	int		error;
	ssize_t	len;
	ssize_t	last_read;
}				t_buffer;

typedef struct s_line
{
	char	*str;
	int		error;
	ssize_t	len;
}				t_line;

char*	get_next_line(int fd, int *error);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_free_and_null(void **ptr);

#endif
