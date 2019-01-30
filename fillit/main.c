/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:44:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/30 23:59:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*all;
	t_tetri	*lsttetris;
	char	**map;

	if (ac != 2)
		ft_putendl("usage : ./fillit input_file\n");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putendl("error");
	else
	{
		if ((all = ft_tetrisvalid(fd)) == 0)
			ft_putendl("error");
		else
		{
			lsttetris = ft_get_tetriminos(all);
			ft_put_up_left(lsttetris);
			ft_print_map(ft_solve((map = ft_create_map(ft_get_map_size(all))),
						lsttetris, ft_get_map_size(all)));
			ft_free_list(lsttetris);
			ft_free_map(map);
			free(all);
		}
	}
	return (0);
}
