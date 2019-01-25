/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:43:12 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/25 13:25:46 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int	j;

	j = 0;
	while (map[j] != 0)
	{
		ft_putstr(map[j++]);
		ft_putchar('\n');
	}
}

int		ft_get_map_size(char *str)
{
	int	res;

	res = ft_sqrt_fillit(ft_num_tetri(str) * 4);
	return (res);
}

char	**ft_create_map(int size_m)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = malloc(sizeof(char *) * (size_m + 1))))
		return (0);
	while (i < size_m)
		if (!(map[i++] = malloc(sizeof(char) * (size_m + 1))))
			return (0);
	i = 0;
	while (j < size_m)
	{
		while (i < size_m)
			map[j][i++] = '.';
		map[j][i] = '\0';
		i = 0;
		j++;
	}
	map[j] = 0;
	return (map);
}
