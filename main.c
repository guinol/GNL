/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <lagirard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:11:31 by lagirard          #+#    #+#             */
/*   Updated: 2017/03/01 23:08:31 by agarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*buff;
	char	**line;
//	int		size_buff;
//	char	***table;

	if (ac != 2)
	{
		ft_putendl("FAUX");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error());
	/*buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if ((read(fd, buff, BUFF_SIZE)) < 0)
		return (ft_error());*/
	while(get_next_line(fd, line) < 0)
	{
		ft_putendl(line);
	}
	close(fd);
	return (0);
}
