#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 30

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);
#endif
