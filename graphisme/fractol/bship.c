/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:42:30 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/08 14:53:27 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
#include <math.h>

//https://lodev.org/cgtutor/juliamandelbrot.html

t_fract	ft_fillbship(t_fract b, double x, double y, t_window *infos)
{
	(void)infos;
	// b.cr = x / infos->value.zoom - infos->value.x1;
	// b.ci = y / infos->value.zoom - infos->value.y1;
	b.cr = (x + infos->value.dx) / infos->value.zmx1 - infos->value.zmx2 + infos->value.mvx;
	b.ci = infos->value.zmy2 - (y + infos->value.dy) / infos->value.zmy1 + infos->value.mvy;
	b.zr = 0;
	b.zi = 0;
	//ft_putendl("dans fill");
	return (b);
}

static int	ft_iterbship(t_fract b, double x, double y, t_window *infos)
{
	double	zr2;
	double	zi2;
	double	tmp;
	// double  dr;
	// double	di;
	int		i;


	b = ft_fillbship(b, x, y, infos);
	//ft_putendl("apres le fill");
	i = 0;
	while (i < infos->value.max_iter && b.zr * b.zr + b.zi * b.zi < 4)
	{
		zr2 = b.zr * b.zr;
		zi2 = b.zi * b.zi;
		//ft_putendl("c'est dans iter ");
		tmp = zr2 - zi2 + b.cr;
		b.zi = fabs(2 * b.zr * b.zi) + b.ci;
		b.zr = tmp;
		i++;
	}
	return (i);
}

int	ft_bship(t_window *infos)
{
	t_fract		b;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	printf("b.cr = %f\n", b.cr);
	printf("b.ci = %f\n", b.ci);
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			//j = ft_fillnewton(j, x, y, infos);
			//ft_putendl("ou ca");
			i = ft_iterbship(b, x, y, infos);
			//ft_putendl("ah ");
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
	return (0);
}