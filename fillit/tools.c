/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:30:28 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/29 13:50:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_num_tetri(char *str)
{
	int	nbc;
	int	sep;
	int	i;

	i = 0;
	sep = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			sep++;
		i++;
	}
	nbc = i - sep;
	return (nbc / 20);
}

int			ft_sqrt_fillit(int nb)
{
	int	res;
	int i;

	i = 0;
	res = 0;
	if (nb < 0)
		return (0);
	while (res != nb)
	{
		if (res > nb)
			return (i);
		i++;
		res = i * i;
		if (i == 50000)
			return (0);
	}
	return (i);
}

char		*ft_free_join(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	ft_strdel(&s1);
	return (s3);
}

void	ft_free_map(char **map)
{
	int	i;
	int s_map;

	s_map = ft_get_map_line(map);
	i = 0;
	while (i < s_map)
	{
		ft_strdel(&map[i]);
		i++;
	}
	ft_strdel(map);
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
	//ft_putnbr(i);
	//ft_putchar('\n');
	return (i);
}