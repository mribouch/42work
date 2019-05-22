/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:42:30 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/20 14:37:48 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static t_fract	ft_fillbship(t_fract b, double x, double y, t_window *infos)
{
	(void)infos;
	b.cr = (x + infos->value.dx) / infos->value.zmx1
		- infos->value.zmx2 - 0.5;
	b.ci = infos->value.zmy2 - (y + infos->value.dy)
		/ infos->value.zmy1 - 0.5;
	b.zr = 0;
	b.zi = 0;
	return (b);
}

static int		ft_iterbship(t_fract b, double x, double y, t_window *infos)
{
	double	zr2;
	double	zi2;
	double	tmp;
	int		i;

	b = ft_fillbship(b, x, y, infos);
	i = 0;
	while (i < infos->value.max_iter && b.zr * b.zr + b.zi * b.zi < 4)
	{
		zr2 = b.zr * b.zr;
		zi2 = b.zi * b.zi;
		tmp = zr2 - zi2 + b.cr;
		b.zi = fabs(2 * b.zr * b.zi) + b.ci;
		b.zr = tmp;
		i++;
	}
	return (i);
}

int				ft_bship(t_window *infos)
{
	t_fract		b;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	b.cr = 0;
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			i = ft_iterbship(b, x, y, infos);
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	if (infos->value.cid == 2 || infos->value.cid == 3)
		infos = ft_put_slide_hsv(infos, 480, 25);
	mlx_put_image_to_window(infos->mlx_ptr
		, infos->win_ptr, infos->img_ptr, 0, 0);
	return (0);
}
