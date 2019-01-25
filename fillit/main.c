/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:44:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/25 14:36:57 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*void	ft_print_all_lst(t_tetri *tetris)
{
	int	i;
	int	nbt;

	i = 0;
	nbt = 1;
	ft_putendl("#### DEBUT DU PRINT ####");
	ft_putchar('\n');
	while (tetris != NULL)
	{
		ft_putendl("DEBUG entre dans tant tetris!= NULL");
		ft_putstr("-- Tetriminos numero : ");
		ft_putnbr(nbt++);
		ft_putchar('\n');
		while (tetris->tetri[i] != 0)
		{
			ft_putendl(tetris->tetri[i]);
			i++;
		}
		i = 0;
		ft_putstr("width : ");
		ft_putnbr(tetris->width);
		ft_putchar('\n');
		ft_putstr("height : ");
		ft_putnbr(tetris->height);
		ft_putchar('\n');
		ft_putstr("key : ");
		ft_putchar(tetris->key);
		ft_putchar('\n');
		ft_putendl("SUIVANT");
		tetris = tetris->next;
	}
}*/

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
