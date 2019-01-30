/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:06:53 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/29 21:25:23 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_remove(t_tetri *begin, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j])
		{
			if (map[i][j] == begin->key)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

char	**ft_place(t_tetri *begin, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (begin->tetri[i][j] == '#')
				map[i + begin->y][j + begin->x] = begin->key;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

int		ft_check_place(t_tetri *begin, char **map, int s_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((begin->tetri[i][j] == '#') &&
					(i + begin->y >= s_map || j + begin->x >= s_map))
				return (0);
			if (begin->tetri[i][j] == '#' &&
					map[i + begin->y][j + begin->x] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		ft_rec_place(t_tetri *begin, char **map, int s_map)
{
	if (begin != NULL)
	{
		while (begin->y * begin->x < s_map * s_map)
		{
			if (ft_check_place(begin, map, s_map) == 1)
			{
				map = ft_place(begin, map);
				if (ft_rec_place(begin->next, map, s_map) == 1)
					return (1);
				map = ft_remove(begin, map);
			}
			if (begin->x < s_map)
				begin->x++;
			else
			{
				begin->x = 0;
				begin->y++;
			}
		}
		begin->x = 0;
		begin->y = 0;
		return (0);
	}
	return (1);
}

char	**ft_solve(char **map, t_tetri *begin, int s_map)
{
	ft_put_up_left(begin);
	while (ft_rec_place(begin, map, s_map) == 0)
	{
		ft_free_map(map);
		s_map++;
		map = ft_create_map(s_map);
		begin->x = 0;
		begin->y = 0;
	}
	return (map);
}
