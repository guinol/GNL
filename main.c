#include "libft.h"
#include "get_next_line.h"

int	main (int ac, char **av)
{
	int	fd;
	char		**line;

	if (ac != 2)
	{
		ft_putendl("FAUX");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	line = (char**)malloc(sizeof(char*));
	while (get_next_line(fd, line) < 1)
	{
		ft_putendl(line[0]);
	}
	close(fd);
	read(0, NULL, 1);
	//getchar();
	return (0);
}
