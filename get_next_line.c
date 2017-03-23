#include "libft.h"
#include "get_next_line.h"

void	ft_ini_file(int fd, s_lst_files files)
{
	char *buff;
	char *cont;
	s_lst_files file;

	ft_bzero(buff, BUFF_SIZE);
	while ((read(fd, buff, BUFF_SIZE)) < 0)
	{
		cont = ft_strjoin(cont, buff);
	}
	if (*files != NULL)
	{
		while (files->next != NULL)
			files = files->next;
		*files->next = file;
	}
	file.fd = fd;
	file->lines = ft_strsplit(cont, '\n');
	file.index = 0;
	file.end = 0;
	file.next = NULL;
	*files = file;
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
		files = files->next;
	}
	if (i == 1)
		return(0);
	else
		ft_ini_fd(fd);
	return (0);
}

char *ft_get_line(int fd, t_lst_files)
{
	while (files->next != NULL)
	{
		if (files.fd == fd)
		{
			files.index++;
			return (files.lines[files.index - 1]);
		}
		files = files->next;
	}
	if (files.fd == fd)
	{
		files.index++;
		return (files.lines[files.index - 1]);
	}
	return (NULL);
}

int get_next_line(const int fd, char **line)
{
	char *buff;
	static t_lst_files **files;

	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if ((read(fd, *buff, BUFF_SIZE)) < 0)
		return (-1);
	if (!(line = (char**)malloc(sizeof(char*) * 1)))
		return (-1);
	ft_check_fd(fd, *files);
	*line = ft_get_line(fd, files);
	return (0);
}
