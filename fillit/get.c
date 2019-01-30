/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:51:34 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/29 21:02:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_get_str(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tetri;

	i = 0;
	if (!(tetri = malloc(sizeof(char*) * 5)))
		return (0);
	while (i < 4)
		if (!(tetri[i++] = malloc(sizeof(char) * 5)))
			return (0);
	i = 0;
	j = 0;
	while (i <= 19 && (k = -1))
	{
		while (str[i] != '\n')
			tetri[j][++k] = str[i++];
		tetri[j++][++k] = '\0';
		i++;
	}
	tetri[j] = 0;
	return (tetri);
}

t_tetri	*ft_create_tetri(char **str, char key)
{
	t_tetri *tetris;

	tetris = ft_memalloc(sizeof(t_tetri));
	tetris->tetri = str;
	tetris->key = key;
	tetris->x = 0;
	tetris->y = 0;
	tetris->next = NULL;
	return (tetris);
}

int		ft_get_map_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
			j++;
		i++;
		j = 0;
	}
	return (i);
}

t_tetri	*ft_get_tetriminos(char *str)
{
	t_tetri	*tetris;
	t_tetri	*ret;
	char	letter;
	int		nbt;

	letter = 'A';
	nbt = ft_num_tetri(str) - 1;
	tetris = ft_create_tetri(ft_get_str(str), letter++);
	ret = tetris;
	str += 21;
	while (nbt-- > 0)
	{
		tetris->next = ft_create_tetri(ft_get_str(str), letter++);
		tetris = tetris->next;
		str += 21;
	}
	return (ret);
}
