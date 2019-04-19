/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:13:11 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/19 15:13:38 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	*ft_fill_pixel_new(t_window *infos, t_var c, t_bresen b, float nbp)
{
	int		i;
	float	x;
	float	y;

	x = b.x;
	y = b.y;
	i = (int)x + (int)y * infos->width;
	if (x >= infos->width || y >= infos->height || x < 0 || y < 0)
		;
	else
		infos->img[i] = ft_lerp(b.i, c.color1, c.color2, nbp);
	return (infos->img);
}

static void	ft_sec_c(t_bresen *b, t_window *infos, t_point v1, t_point v2)
{
	t_var	c;

	c.color1 = v1.color;
	c.color2 = v2.color;
	b->cumul = b->dy / 2;
	b->i = 1;
	while (b->i++ <= b->dy)
	{
		b->y += b->yinc;
		b->cumul += b->dx;
		if (b->cumul >= b->dy)
		{
			b->cumul -= b->dy;
			b->x += b->xinc;
		}
		infos->img = ft_fill_pixel_new(infos, c, *b, b->dy);
	}
}

static void	ft_first_c(t_bresen *b, t_window *infos, t_point v1, t_point v2)
{
	t_var	c;

	c.color1 = v1.color;
	c.color2 = v2.color;
	b->cumul = b->dx / 2;
	while (b->i++ <= b->dx)
	{
		b->x += b->xinc;
		b->cumul += b->dy;
		if (b->cumul >= b->dx)
		{
			b->cumul -= b->dx;
			b->y += b->yinc;
		}
		infos->img = ft_fill_pixel_new(infos, c, *b, b->dx);
	}
}

void		ft_line_new(t_window *infos, t_point v1, t_point v2)
{
	t_bresen	b;
	t_var		c;

	c.color1 = v1.color;
	c.color2 = v2.color;
	b.x = v1.x + infos->width / 2;
	b.y = v1.y + infos->height / 2;
	b.dx = v2.x - v1.x;
	b.dy = v2.y - v1.y;
	b.i = 1;
	b.xinc = (b.dx > 0) ? 1 : -1;
	b.yinc = (b.dy > 0) ? 1 : -1;
	b.dx = fabsf(b.dx);
	b.dy = fabsf(b.dy);
	if (b.x > infos->width || b.y > infos->height || b.x < 0 || b.y < 0)
		;
	else
	{
		infos->img = ft_fill_pixel_new(infos, c, b, b.dx);
		if (b.dx > b.dy)
			ft_first_c(&b, infos, v1, v2);
		else
			ft_sec_c(&b, infos, v1, v2);
	}
}
