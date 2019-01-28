/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:51:34 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/28 19:31:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_height(char *str)
{
	int	i;
	int	line;
	int	max;
	int	min;

	line = 1;
	i = 0;
	min = 4;
	max = 1;
	while (i <= 19)
	{
		if (i == 5 || i == 10 || i == 15)
			line++;
		if (str[i++] == '#')
		{
			if (min > line)
				min = line;
			if (max < line)
				max = line;
		}
	}
	return (max - min + 1);
}

int		ft_get_width(char *str)
{
	int	i;
	int	min;
	int max;
	int	lim;

	i = 0;
	min = 4;
	max = 1;
	lim = 1;
	while (i <= 19)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
			lim = 0;
		if (str[i++] == '#')
		{
			if (min > lim)
				min = lim;
			if (max < lim)
				max = lim;
		}
		lim++;
	}
	return (max - min + 1);
}

char	**ft_get_str(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tetri;

	i = 0;
	if (!(tetri = malloc(sizeof(char*) * 5)))
		return (0);
	while (i <= 4)
	{
		if (!(tetri[i++] = malloc(sizeof(char) * 5)))
			return (0);
	}
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

t_tetri	*ft_create_tetri(char **str, char key, int width, int height)
{
	t_tetri *tetris;

	tetris = ft_memalloc(sizeof(t_tetri));
	tetris->tetri = str;
	tetris->key = key;
	tetris->width = width;
	tetris->height = height;
	tetris->x = 0;
	tetris->y = 0;
	tetris->next = NULL;
	return (tetris);
}

t_tetri	*ft_get_tetriminos(char *str)
{
	t_tetri	*tetris;
	t_tetri	*ret;
	char	*tmp;
	char	letter;
	int		nbt;

	letter = 'A';
	nbt = ft_num_tetri(str) - 1;
	tetris = ft_create_tetri(ft_get_str(str), letter++, ft_get_width(str)
			, ft_get_height(str));
	ret = tetris;
	tmp = str;
	str = ft_strsub(str, 21, ft_strlen(str));
	free(tmp);
	while (nbt != 0)
	{
		tetris->next = ft_create_tetri(ft_get_str(str), letter++,
				ft_get_width(str), ft_get_height(str));
		tetris = tetris->next;
		if (nbt-- >= 1)
		{
			tmp = str;
			str = ft_strsub(str, 21, ft_strlen(str));
			free(tmp);
		}
	}
	return (ret);
}
