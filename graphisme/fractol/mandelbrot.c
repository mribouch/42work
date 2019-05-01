/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:26 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:41 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

#include <stdio.h>


// t_fract	ft_itermandel(t_window *infos, t_fract m)
// {
// 	int	r;
// 	int	j;
// 	int	i;

// 	i = 0;
// 	r = m.zr;
// 	j = m.zi;
// 	m.zr = r * r - j * j + m.cr;
// 	m.zi = 2 * r * j + m.ci;
// 	return (m);
// }

t_fract	ft_fillmandel(t_fract m, double x, double y, t_window *infos)
{
	m.cr = (x + infos->value.dx) / infos->value.zmx1 - infos->value.zmx2 - 0.5;
	m.ci = infos->value.zmy2 - (y + infos->value.dy) / infos->value.zmy1;
	m.zr = 0;
	m.zi = 0;
	return (m);
}

int	ft_mandel(t_window *infos)
{
	t_fract	m;
	double		zr2;
	double		zi2;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			m = ft_fillmandel(m, x, y, infos);
			i = 0;
			while (i < infos->value.max_iter)
			{
				zr2 = m.zr * m.zr;
				zi2 = m.zi * m.zi;
				m.zi = 2 * m.zi * m.zr + m.ci;
				m.zr = zr2 - zi2 + m.cr;
				if (zr2 + zi2 >= 4)
					break;
				i++;
			}
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
	return (0);
}
