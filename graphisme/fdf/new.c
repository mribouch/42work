/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:26:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/10 12:15:18 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_over_new(t_window *infos, int v)
{
	if (infos->iso[v].z <= 1.0f)
		return (1);
	return (0);
}

void	ft_draw_persp(t_window *infos)
{
	int	i;
	int	j;
	int	v;

	i = 0;
	j = 0;
	v = 0;
	while (i < infos->mapinf->height)
	{
		while (j < infos->mapinf->width)
		{
			if (j < infos->mapinf->width - 1 && ft_over_new(infos, v) == 0)
				ft_line_new(infos, infos->iso[v], infos->iso[v + 1]);
			if (i < infos->mapinf->height - 1 && ft_over_new(infos, v) == 0)
				ft_line_new(infos, infos->iso[v],
			infos->iso[v + infos->mapinf->width]);
			v++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_iso(t_window *infos)
{
	int	i;
	int	j;
	int	v;

	i = 0;
	j = 0;
	v = 0;
	while (i < infos->mapinf->height)
	{
		while (j < infos->mapinf->width)
		{
			if (j < infos->mapinf->width - 1)
				ft_line_new(infos, infos->iso[v], infos->iso[v + 1]);
			if (i < infos->mapinf->height - 1)
				ft_line_new(infos, infos->iso[v],
			infos->iso[v + infos->mapinf->width]);
			v++;
			j++;
		}
		j = 0;
		i++;
	}
}

t_point	*ft_new(t_window *infos, t_point *vertices, char **col)
{
	t_newv	s;

	s.i = 0;
	s.j = 0;
	s.dx = 0;
	s.dy = 0;
	s.v = 0;
	while (infos->mapinf->map[s.i] != 0)
	{
		while (s.j < infos->mapinf->width)
		{
			vertices[s.v].x = s.dx - infos->mapinf->width * 10;
			vertices[s.v].y = s.dy - infos->mapinf->height * 10;
			vertices[s.v].z = (infos->mapinf->map[s.i][s.j]);
			vertices[s.v].color = ft_hex2int(col[s.v]);
			s.j++;
			s.dx = s.dx + 20;
			s.v++;
		}
		s.i++;
		s.dx = 0;
		s.j = 0;
		s.dy = 20 * s.i;
	}
	return (vertices);
}
