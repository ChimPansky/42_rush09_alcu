#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE 1
# endif

// Helper Functions
int		ft_isspace(char c);
size_t	ft_strlen(const char	*s);
ssize_t	ft_putstr_fd(int fd, char *s);

#endif
