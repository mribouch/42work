/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:44:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/28 17:15:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*all;
	t_tetri	*lsttetris;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit input_file\n");
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if ((all = ft_tetrisvalid(fd)) == 0)
			ft_putendl("error");
		else
		{
			lsttetris = ft_get_tetriminos(all);
			ft_put_up_left(lsttetris);
			ft_print_map(ft_solve(ft_create_map(ft_get_map_size(all)),
						lsttetris, ft_get_map_size(all)));
		}
	}
	return (0);
}
