/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:12:26 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/13 16:02:15 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_fract	ft_fillmandel(t_fract m, double x, double y, t_window *infos)
{
	m.cr = (x + infos->value.dx) / infos->value.zmx1 - infos->value.zmx2 - 0.5;
	m.ci = infos->value.zmy2 - (y + infos->value.dy) / infos->value.zmy1;
	m.zr = 0;
	m.zi = 0;
	return (m);
}

static int	ft_itermandel(t_fract m, double x, double y, t_window *infos)
{
	double	zr2;
	double	zi2;
	int		i;
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
	return (i);
}

int	ft_mandel(t_window *infos)
{
	t_fract	m;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	m.cr = 0;
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			i = ft_itermandel(m, x, y, infos);
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	if (infos->value.cid == 2 || infos->value.cid == 3)
		infos = ft_put_slide_hsv(infos, 480, 25);
	//infos = ft_putmenu(infos);
	mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
	return (0);
}

//https://www.math.univ-toulouse.fr/~cheritat/wiki-draw/index.php/Mandelbrot_set