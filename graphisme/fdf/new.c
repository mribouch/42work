/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:26:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/25 18:24:59 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


int		*ft_fill_pixel_new(t_window *infos, int x, int y, int color1, int color2, int j, float nbp)
{
	int	i;

	(void)color2;
	i = x + y * infos->width;
	if (x >= infos->width || y >= infos->height || x < 0 || y < 0)
		;
	else
		infos->img[i] = ft_lerp(j, color1, color2, nbp);
	return (infos->img);
}

// void	ft_line_new(t_window *infos, t_point vertices1, t_point vertices2)
// {
// 	float	dx;
// 	float	dy;
// 	int		i;
// 	int		xinc;
// 	int		yinc;
// 	float	cumul;
// 	float	x;
// 	float	y;
// 	x = vertices1.x + infos->width / 2;
// 	y = vertices1.y + infos->height / 2;
// 	dx = vertices2.x - vertices1.x;
// 	dy = vertices2.y - vertices1.y;
// 	i = 1;
// 	xinc = (dx > 0) ? 1 : -1;
// 	yinc = (dy > 0) ? 1 : -1;
// 	dx = fabsf(dx);
// 	dy = fabsf(dy);
// 	if (x > infos->width || y > infos->height|| x < 0|| y < 0)
// 		 ;
// 	else
// 	{
// 		infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
// 		if (dx > dy)
// 		{
// 			cumul = dx / 2;
// 			while (i++ <= dx)
// 			{
// 				x += xinc ;
// 				cumul += dy ;
// 				if (cumul >= dx)
// 				{
// 					cumul -= dx;
// 					y += yinc;
// 				}
// 				infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
// 			}
// 		}
// 		else
// 		{
// 			cumul = dy / 2;
// 			i = 1;
// 			while (i++ <= dy)
// 			{
// 				y += yinc;
// 				cumul += dx;
// 				if (cumul >= dy)
// 				{
// 					cumul -= dy;
// 					x += xinc;
// 				}
// 				infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dy);
// 			}
// 		}
// 	}
// }
// void	ft_line_new(t_window *infos, t_point vertices1, t_point vertices2)
// {
// 	t_bresen b;

// 	b.x = vertices1.x + infos->width / 2;
// 	b.y = vertices1.y + infos->height / 2;
// 	b.dx = vertices2.x - vertices1.x;
// 	b.dy = vertices2.y - vertices1.y;
// 	b.i = 1;
// 	b.xinc = (b.dx > 0) ? 1 : -1;
// 	b.yinc = (b.dy > 0) ? 1 : -1;
// 	b.dx = fabsf(b.dx);
// 	b.dy = fabsf(b.dy);
// 	if (b.x > infos->width || b.y > infos->height|| b.x < 0|| b.y < 0)
// 		 ;
// 	else
// 	{
// 		infos->img = ft_fill_pixel_new(infos, (int)b.x, (int)b.y, vertices1.color, vertices2.color, b.i, b.dx);
// 		if (b.dx > b.dy)
// 		{
// 			b.cumul = b.dx / 2;
// 			while (b.i++ <= b.dx)
// 			{
// 				b.x += b.xinc ;
// 				b.cumul += b.dy ;
// 				if (b.cumul >= b.dx)
// 				{
// 					b.cumul -= b.dx;
// 					b.y += b.yinc;
// 				}
// 				infos->img = ft_fill_pixel_new(infos, (int)b.x, (int)b.y, vertices1.color, vertices2.color, b.i, b.dx);
// 			}
// 		}
// 		else
// 		{
// 			b.cumul = b.dy / 2;
// 			b.i = 1;
// 			while (b.i++ <= b.dy)
// 			{
// 				b.y += b.yinc;
// 				b.cumul += b.dx;
// 				if (b.cumul >= b.dy)
// 				{
// 					b.cumul -= b.dy;
// 					b.x += b.xinc;
// 				}
// 				infos->img = ft_fill_pixel_new(infos, (int)b.x, (int)b.y, vertices1.color, vertices2.color, b.i, b.dy);
// 			}
// 		}
// 	}
// }

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

void	ft_draw_new(t_window *infos)
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
				ft_line_new(infos, infos->vertices[v], infos->vertices[v + 1]);
			if (i < infos->mapinf->height - 1)
				ft_line_new(infos, infos->vertices[v],
					infos->vertices[v + infos->mapinf->width]);
			v++;
			j++;
		}
		j = 0;
		i++;
	}
}

t_point		*ft_new(t_window *infos, t_point *vertices, char **col)
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
