/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:13:11 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/25 18:33:37 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void	ft_sec_c(t_bresen *b, t_window *infos, t_point vertices1, t_point vertices2)
{
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
		infos->img = ft_fill_pixel_new(infos, (int)b->x, (int)b->y, vertices1.color, vertices2.color, b->i, b->dy);
	}
}

void	ft_first_c(t_bresen *b, t_window *infos, t_point vertices1, t_point vertices2)
{
	b->cumul = b->dx / 2;
	while (b->i++ <= b->dx)
	{
		b->x += b->xinc ;
		b->cumul += b->dy ;
		if (b->cumul >= b->dx)
		{
			b->cumul -= b->dx;
			b->y += b->yinc;
		}
		infos->img = ft_fill_pixel_new(infos, (int)b->x, (int)b->y, vertices1.color, vertices2.color, b->i, b->dx);
	}
}

void	ft_line_new(t_window *infos, t_point vertices1, t_point vertices2)
{
	t_bresen b;

	b.x = vertices1.x + infos->width / 2;
	b.y = vertices1.y + infos->height / 2;
	b.dx = vertices2.x - vertices1.x;
	b.dy = vertices2.y - vertices1.y;
	b.i = 1;
	b.xinc = (b.dx > 0) ? 1 : -1;
	b.yinc = (b.dy > 0) ? 1 : -1;
	b.dx = fabsf(b.dx);
	b.dy = fabsf(b.dy);
	if (b.x > infos->width || b.y > infos->height|| b.x < 0|| b.y < 0)
		 ;
	else
	{
		infos->img = ft_fill_pixel_new(infos, (int)b.x, (int)b.y, vertices1.color, vertices2.color, b.i, b.dx);
		if (b.dx > b.dy)
			ft_first_c(&b, infos, vertices1, vertices2);
		else
			ft_sec_c(&b, infos, vertices1, vertices2);
	}
}