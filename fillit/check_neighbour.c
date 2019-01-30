/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_neighbour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:09:32 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/30 18:26:24 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_newblock(int nbl)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	while (i <= 26)
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
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\0') && (nbc != 6 && nbc != 8))
			return (0);
		if ((str[i] == '\n' && str[i + 1] == '\n') && (nbc != 6 && nbc != 8))
			return (0);
		if ((str[i] == '\n' && str[i + 1] == '\n') && (nbc == 6 || nbc == 8))
			nbc = 0;
		str[i] == '\n' ? nbl++ : 0;
		(str[i] == '#' && str[i + 1] == '#') ? nbc++ : 0;
		if (str[i] == '#' && str[i + 5] == '#' && ft_end_tetri(nbl) == 0)
			nbc++;
		(str[i] == '#' && str[i - 1] == '#') ? nbc++ : 0;
		if (str[i] == '#' && str[i - 5] == '#' && ft_newblock(nbl) == 0)
			nbc++;
		i++;
	}
	return (1);
}

int			ft_check_neighbour(char *str)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = 1;
	while (str[i])
	{
		str[i] == '\n' ? nbl++ : 0;
		if (i == 0 && str[i] == '#' && str[i + 1] != '#' && str[i + 5] != '#')
			return (0);
		if (ft_newblock(nbl) == 1 && str[i] == '#' && str[i + 1] != '#'
			&& str[i + 5] != '#' && str[i - 1] != '#')
			return (0);
		if (str[i] == '#' && str[i + 1] != '#' && str[i + 5] != '#'
			&& str[i - 1] != '#' && str[i - 5] != '#')
			return (0);
		i++;
	}
	if (ft_check_connect(str) != 1)
		return (0);
	return (1);
}
