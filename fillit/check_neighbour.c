/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_neighbour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:09:32 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/24 14:27:59 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_newblock(nbl)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	while (i  <= 26)
	{
		if (nbl == res)
			return (1);
		res = res + 5;
		i++;
	}
	return (0);
}

static int	ft_check_connect(char *str)
{
	int	i;
	int	nbc;
	int	nbl;

	i = 0;
	nbc = 0;
	nbl = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i + 1] == '\0') && (nbc != 6 && nbc != 8))
		{
			//ft_putstr("debug entre si dernier nl, nbc = ");
			//ft_putnbr(nbc);
			//ft_putchar('\n');
			return (0);
		}
		if ((str[i] == '\n' && str[i + 1] == '\n') && (nbc != 6 && nbc != 8))
		{
		//	ft_putstr("debug entre si nb et pas bon nombre, nbc = ");
		//	ft_putnbr(nbc);
		//	ft_putchar('\n');
			return (0);
		}
		if ((str[i] == '\n' && str[i + 1] == '\n') && (nbc == 6 || nbc == 8))
		{
		//	ft_putstr("debug entre si nb, et bon nombre, nbc = ");
		//	ft_putnbr(nbc);
		//	ft_putchar('\n');
			nbc = 0;
		}
		if (str[i] == '\n')
			nbl++;
		if (str[i] == '#' && str[i + 1] == '#')
		{
		//	ft_putendl("debug i + 1");
			nbc++;
		}
		if (str[i] == '#' && str[i + 5] == '#' && ft_end_tetri(nbl) == 0)
		{
		//	ft_putendl("debug i + 5");
			nbc++;
		}
		if (str[i] == '#' && str[i - 1] == '#')
		{
		//	ft_putendl("debug i - 1");
			nbc++;
		}
		if (str[i] == '#' && str[i - 5] == '#' && ft_newblock(nbl) == 0)
		{
		//	ft_putendl("debug i - 5");
			nbc++;
		}
//		ft_putstr("i = ");
//		ft_putnbr(i);
//		ft_putchar('\n');
		i++;
	}
	return (1);
}

int	ft_check_neighbour(char *str)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = 1;
	while (str[i] != '\0')
	{	
		if (str[i] == '\n')
			nbl++;
		 if (i == 0 && str[i] == '#')
			if (str[i + 1] != '#' && str[i + 5] != '#')
				return (0);
		if (ft_newblock(nbl) == 1 && str[i] == '#')
			if (str[i + 1] != '#' && str[i + 5] != '#' && str[i - 1] != '#')
				return (0);
		if (str[i] == '#')
		{
			if (str[i + 1] != '#' && str[i + 5] != '#' && str[i - 1] != '#' && str[i - 5] != '#')
				return (0);
		}
		i++;
	}
	if (ft_check_connect(str) != 1)
		return (0);
	return (1);
}
