/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:32:07 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/19 18:29:18 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*ft_fill_sizem(t_map *mapinf, int *nbl, char *full)
{
	mapinf->height = ft_rd_nbl(full);
	mapinf->width = ft_rd_nbc(full);
	*nbl = ft_rd_nbl(full);
	return (mapinf);
}

static int		**ft_fill_map2(t_map *mapinf, char *full, int k, int nbl)
{
	int	i;

	i = 0;
	while (full[k] != '\0')
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
		k++;
	}
	mapinf->map[nbl] = 0;
	return (mapinf->map);
}

static int		**ft_fill_map(t_map *mapinf, char *full)
{
	int		k;
	int		nbl;

	k = 0;
	nbl = 0;
	mapinf->map = ft_fill_map2(mapinf, full, k, nbl);
	return (mapinf->map);
}

static char		*ft_create_full(int fd)
{
	char	*line;
	char	*full;
	int		lenc;

	lenc = 0;
	if (get_next_line(fd, &line) <= 0)
		return (0);
	full = ft_strnew(1);
	if (ft_check_return(line, full) == 0)
		return (0);
	if (line[0] == '\0')
		return (0);
	if (ft_check_error(full, line) == 0)
		return (0);
	full = ft_fill_full(full, line, &lenc);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_parse_line(full, line, lenc) == 0)
			return (0);
		full = ft_free_join(full, line);
		free(line);
		full = ft_free_join(full, "\n");
	}
	return (full);
}

t_map			*ft_read(int fd, t_map *mapinf, char ***col)
{
	int		nbl;
	int		i;
	char	*full;
	char	**allpoint;

	i = 0;
	full = ft_create_full(fd);
	if (full == 0)
		return (0);
	mapinf = ft_fill_sizem(mapinf, &nbl, full);
	allpoint = ft_strsplit_fdf(full);
	if (!(mapinf->map = malloc(sizeof(int*) * (mapinf->height + 1))))
		return (0);
	while (nbl > 0)
	{
		if (!(mapinf->map[i++] = malloc(sizeof(int) * (mapinf->width + 1))))
			return (0);
		nbl--;
	}
	*col = ft_get_col(allpoint, *col);
	mapinf->map = ft_fill_map(mapinf, full);
	ft_free_dchar(allpoint);
	free(full);
	return (mapinf);
}
