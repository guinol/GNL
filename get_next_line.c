#include "libft.h"
#include "get_next_line.h"

ft_ini_file(int fd, s_lst_files files)
{
	char *buff;
	char *cont;

	ft_bzero(buff, BUFF_SIZE);
	if ()
}

int	ft_check_fd(int fd, t_lst_files *files)
{
	int i;

	i = 0;
	if (files == NULL)
		ini_fd(fd);
	while (files->next != NULL)
	{
		if(files.fd == fd)
			i++;
	}
}

int get_next_line(const int fd, char **line)
{
	char *buff; 
	static t_lst_files **files;

	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if ((read(fd, *buff, BUFF_SIZE)) < 0)
		return (-1);
	if (!(line = (char**)malloc(sizeof(char*) * 1000)))
		return (-1);
	
	ft_check_fd(fd, *files)
	return (0);
}
