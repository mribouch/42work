/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:49:50 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 12:22:20 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fill_circle(t_window *infos, t_point c, int x, int y)
{
	infos->img[(c.x + x) + (c.y + y) * infos->width] = c.color;
	infos->img[(c.x + y) + (c.y + x) * infos->width] = c.color;
	infos->img[(c.x - x) + (c.y + y) * infos->width] = c.color;
	infos->img[(c.x - y) + (c.y + x) * infos->width] = c.color;
	infos->img[(c.x + x) + (c.y - y) * infos->width] = c.color;
	infos->img[(c.x + y) + (c.y - x) * infos->width] = c.color;
	infos->img[(c.x - x) + (c.y - y) * infos->width] = c.color;
	infos->img[(c.x - y) + (c.y - x) * infos->width] = c.color;
}

void		ft_fullcircle(t_window *infos, t_point c, int r, int color)
{
	int	x;
	int	y;
	int	d;

	c.color = color;
	while (r >= 0)
	{
		x = 0;
		y = r;
		d = r - 1;
		while (y >= x)
		{
			ft_fill_circle(infos, c, x, y);
			if (d >= 2 * x)
				d -= 2 * x++ + 1;
			else if (d < 2 * (r - y))
				d += 2 * y-- - 1;
			else
				d += 2 * (y-- - x++ - 1);
		}
		r--;
	}
}

void		ft_circle(t_window *infos, t_point c, int r, int color)
{
	int	x;
	int	y;
	int	d;

	c.color = color;
	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		ft_fill_circle(infos, c, x, y);
		if (d >= 2 * x)
			d -= 2 * x++ + 1;
		else if (d < 2 * (r - y))
			d += 2 * y-- - 1;
		else
			d += 2 * (y-- - x++ - 1);
	}
}
