/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:16:59 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/29 21:31:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_ymin(char **str)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 4;
	while (i < 4)
	{
		while (j < 4)
		{
			if (str[i][j] == '#')
				if (i < min)
					min = i;
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}

int		ft_get_xmin(char **str)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 4;
	while (i < 4)
	{
		while (j < 4)
		{
			if (str[i][j] == '#')
				if (j < min)
					min = j;
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}

char	**ft_put_up(char **tetri, int ymin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (ymin != 0)
				if (tetri[i][j] == '#')
				{
					tetri[i][j] = '.';
					tetri[i - ymin][j] = '#';
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (tetri);
}

char	**ft_put_left(char **tetri, int xmin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tetri[i][j] == '#')
				if (j != 0)
				{
					tetri[i][j] = '.';
					tetri[i][j - xmin] = '#';
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (tetri);
}

t_tetri	*ft_put_up_left(t_tetri *begin)
{
	t_tetri	*tmp;

	tmp = begin;
	while (tmp)
	{
		tmp->tetri = ft_put_left(tmp->tetri, ft_get_xmin(tmp->tetri));
		tmp->tetri = ft_put_up(tmp->tetri, ft_get_ymin(tmp->tetri));
		tmp = tmp->next;
	}
	return (begin);
}
