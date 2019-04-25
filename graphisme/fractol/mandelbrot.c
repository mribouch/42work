/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:26 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/25 18:12:32 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

#include <stdio.h>

t_window	*ft_fill_imgcolor(t_window *infos, int i, double x, double y)
{
	t_hsv	hsv;

	hsv.h = i * 360 / 100 % 360;
	hsv.s = 1.0;
	hsv.v = 1.0;
	if (i == infos->value.max_iter && (x + y * infos->width >= 0
		&& x + y * infos->width < infos->height * infos->width))
		infos->img[(int)x + (int)y * infos->width] = 0x000000;
	else
	{
		infos->img[(int)x + (int)y * infos->width] = ft_hsv2rgb(hsv);
	}
	return (infos);
}

// t_mandel	ft_itermandel(t_window *infos, t_mandel m)
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

t_mandel	ft_fillmandel(t_mandel m, double x, double y, t_window *infos)
{
	m.cr = (x + infos->value.dx) / infos->value.zmx1 - infos->value.zmx2 - 0.5;
	m.ci = infos->value.zmy2 - (y + infos->value.dy) / infos->value.zmy1;
	m.zr = 0;
	m.zi = 0;
	return (m);
}

int	ft_mandel(t_window *infos)
{
	t_mandel	m;
	double		r;
	double		j;
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
				r = m.zr;
				j = m.zi;
				m.zr = r * r - j * j + m.cr;
				m.zi = 2 * r * j + m.ci;
				if (m.zr * m.zr + m.zi * m.zi >= 4)
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
