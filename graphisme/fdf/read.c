/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:32:07 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/25 15:28:16 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**ft_fill_map2(t_map *mapinf, char *full, int k, int nbl)
{
	int	i;

	i = 0;
	while (full[k++] != '\0')
	{
		if (full[k] == '\n')
		{
			nbl++;
			i = 0;
		}
		else if (full[k] >= '0' && full[k] <= '9')
		{
			mapinf->map[nbl][i] = ft_get_num(full, k);
			if (full[k] >= '0' && full[k] <= '9')
			{
				while (full[k] != ' ' && full[k] != '\n')
					k++;
				k = k - 1;
			}
			i++;
		}
	}
	mapinf->map[nbl] = 0;
	return (mapinf->map);
}

int			**ft_fill_map(t_map *mapinf, char *full)
{
	int		k;
	int		nbl;

	k = 0;
	nbl = 0;
	mapinf->map = ft_fill_map2(mapinf, full, k, nbl);
	return (mapinf->map);
}

char		*ft_create_full(int fd)
{
	char	*line;
	char	*full;
	int		lenc;

	lenc = 0;
	full = ft_strnew(1);
	get_next_line(fd, &line);
	if (ft_rd_nbc(line) == -1)
		return (0);
	full = ft_strjoin(full, line);
	full = ft_strjoin(full, "\n");
	lenc = ft_rd_nbc(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_rd_nbc(line) == -1 || lenc != ft_rd_nbc(line))
			return (0);
		full = ft_strjoin(full, line);
		full = ft_strjoin(full, "\n");
	}
	return (full);
}

t_map		*ft_read(int fd, t_map *mapinf, char ***col)
{
	int		nbl;
	int		i;
	char	*full;
	char	**allpoint;

	i = 0;
	full = ft_create_full(fd);
	if (full == 0)
		return (0);
	mapinf->height = ft_rd_nbl(full);
	mapinf->width = ft_rd_nbc(full);
	nbl = ft_rd_nbl(full);
	allpoint = ft_strsplit_fdf(full);
	if (!(mapinf->map = malloc(sizeof(int*) * (mapinf->height + 1))))
		return (0);
	while (nbl > 0)
	{
		if (!(mapinf->map[i] = malloc(sizeof(int) * (mapinf->width + 1))))
			return (0);
		nbl--;
		i++;
	}
	*col = ft_get_col(allpoint, *col);
	mapinf->map = ft_fill_map(mapinf, full);
	return (mapinf);
}
