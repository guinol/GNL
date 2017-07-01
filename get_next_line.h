#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 1

typedef struct			s_file
{
	int			ini;
	char			**lines;
	int			index;
	int			nb_lines;
	int			end;
}				t_file;

int get_next_line(const int fd, char **line);

#endif
