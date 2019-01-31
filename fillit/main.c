/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:44:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/31 15:44:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_solve_fd(int fd)
{
	t_tetri	*lst;
	char	*all;
	char	**map;

	if ((all = ft_tetrisvalid(fd)) == 0)
		ft_putendl("error");
	else
	{
		lst = ft_get_tetriminos(all);
		ft_put_up_left(lst);
		ft_print_map((map = ft_solve(ft_create_map(ft_map_size(all)),
			lst, ft_map_size(all))));
		ft_free_list(lst);
		ft_free_map(map);
		free(all);
	}
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_putendl("error");
		else
			ft_solve_fd(fd);
	}
	else
		ft_putendl("usage : ./fillit input_file");
	return (0);
}
