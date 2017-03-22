#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4

typedef struct			s_lst_files
{
	int			fd;
	char			**lines;
	int			index;
	bool			end;
	struct s_lst_files	*next;
}				t_lst_files

int get_next_line(const int fd, char **line);

#endif
