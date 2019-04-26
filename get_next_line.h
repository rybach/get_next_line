#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define MAX_FD 11000
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
int		get_next_line(const int fd, char **line);
#endif
