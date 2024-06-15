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
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
ssize_t	ft_putstr_fd(int fd, char *s);
void	ft_putnbr_fd(int fd, int n);

#endif
