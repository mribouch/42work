/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:32:24 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/20 18:07:22 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fract	ft_c_if_lock(t_fract j, t_window *infos)
{
	if (infos->value.lock == 0)
	{
		j.cr = infos->cursor.x / (infos->width / 2) - 1;
		j.ci = infos->cursor.y / (infos->height / 2) - 1;
		infos->value.lastcr = infos->cursor.x;
		infos->value.lastci = infos->cursor.y;
	}
	else
	{
		j.cr = infos->value.lastcr / (infos->width / 2) - 1;
		j.ci = infos->value.lastci / (infos->height / 2) - 1;
	}
	return (j);
}

static t_fract	ft_filljulia(t_fract j, double x, double y, t_window *infos)
{
	j.zr = 1.5 * (x - infos->width / 2)
		/ (0.5 * infos->value.zoom * infos->width) + infos->value.mvx;
	j.zi = (y - infos->height / 2)
		/ (0.5 * infos->value.zoom * infos->height) + infos->value.mvy;
	return (j);
}

static int		ft_iterjulia(t_fract j, double x, double y, t_window *infos)
{
	double	zr2;
	double	zi2;
	int		i;

	j = ft_filljulia(j, x, y, infos);
	i = 0;
	while (i < infos->value.max_iter)
	{
		zr2 = j.zr * j.zr;
		zi2 = j.zi * j.zi;
		j.zi = 2 * j.zi * j.zr + j.ci;
		j.zr = zr2 - zi2 + j.cr;
		if (zr2 + zi2 >= 4)
			break ;
		i++;
	}
	return (i);
}

int				ft_julia(t_window *infos)
{
	t_fract		j;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	j.cr = 0;
	j = ft_c_if_lock(j, infos);
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			i = ft_iterjulia(j, x, y, infos);
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	ft_print_sld(infos);
	mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr
		, infos->img_ptr, 0, 0);
	return (0);
}
