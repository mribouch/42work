/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:00:48 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/28 15:37:42 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_end_tetri(int nbl)
{
	int line;
	int	i;

	i = 1;
	line = 4;
	while (i <= 26)
	{
		if (nbl == line)
			return (1);
		line = 4 + 5 * i;
		i++;
	}
	return (0);
}

int		ft_eachblock(int nbl)
{
	int	i;
	int	line;

	i = 1;
	line = 0;
	while (i <= 26)
	{
		if (nbl == line)
			return (1);
		line = i * 5;
		i++;
	}
	return (0);
}

int		ft_parse_line(int nbl, int nbblock, char *line)
{
	int	i;

	i = 0;
	if (ft_eachblock(nbl) == 1)
	{
		if (ft_strlen(line) > 0)
			return (-1);
		nbblock = 0;
	}
	else if (ft_eachblock(nbl) == 0)
	{
		if (ft_strlen(line) != 4)
			return (-1);
		while (line[i] != '\0')
		{
			if (line[i] == '#')
				nbblock++;
			if (line[i] != '.' && line[i] != '#')
				return (-1);
			i++;
		}
	}
	return (nbblock);
}

char	*ft_tetrisvalid(int fd)
{
	char	*line;
	int		nbblock;
	int		nbl;
	char	*full;

	nbblock = 0;
	nbl = 0;
	full = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		nbl++;
		if ((nbblock = ft_parse_line(nbl, nbblock, line)) == -1)
			return (0);
		if (ft_end_tetri(nbl) == 1)
			if (nbblock != 4)
				return (0);
		full = ft_strjoin(full, line);
		full = ft_strjoin(full, "\n");
	}
	if (ft_end_tetri(nbl) == 0)
		return (0);
	if (ft_check_neighbour(full) == 0)
		return (0);
	return (full);
}
