#include "libft.h"
#include "get_next_line.h"

int	ft_cntlines(char **lines)
{
	int i;
	int r;

	i = -1;
	r = 0;
	while (lines[++i])
		r++;
	return (r);
}

void	ft_reading(t_file *file, const int fd)
{
	char *buff;
	char *cont;
	char *tmp;
	char *tmp2;
	int ret;

	buff = ft_strnew(BUFF_SIZE);
	cont = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[ret] = '\0';
		tmp = strdup(buff);
		tmp2 = strdup(cont);
		free(cont);
		cont = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
	}
	free(buff);
	file->lines = ft_strsplit(cont, '\n');
	free(cont);
	file->nb_lines = ft_cntlines(file->lines);
}

void	ft_free2d(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int get_next_line(const int fd, char **line)
{
	static t_file *file;

	if (!file)
	{	
		file = malloc(sizeof(t_file));
		file->index = 0;
		ft_reading(file, fd);
	}
	if (file->index < file->nb_lines)
	{
		line[0] = file->lines[file->index];
		file->index++;
	}
	else
	{
		ft_free2d(file->lines);
		free(file);
		return (1);
	}
	return (0);
}

