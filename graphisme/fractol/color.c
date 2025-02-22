/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:52:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/24 14:41:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static t_hsv	ft_hsv_for_cid(t_window *infos, int i, t_mapjs map)
{
	t_hsv	hsv;

	hsv.h = 0;
	hsv.s = 1.0;
	hsv.v = 1.0;
	if (infos->value.cid == 1)
		hsv.h = i * 360 / infos->value.degre % 360;
	else if (infos->value.cid == 2)
	{
		hsv.h = infos->stock_s.slide1.col_s.h;
		hsv.s = ft_map(map);
	}
	else if (infos->value.cid == 3)
	{
		hsv.h = infos->stock_s.slide1.col_s.h;
		hsv.v = ft_map(map);
	}
	else if (infos->value.cid == 4)
	{
		hsv.h = infos->value.h_per_i;
		hsv.h = hsv.h + infos->value.h_per_i * i;
		while (hsv.h > 359)
			hsv.h -= 360;
	}
	return (hsv);
}

t_window		*ft_fill_imgcolor(t_window *infos, int i, double x, double y)
{
	t_hsv	hsv;
	t_mapjs	map;

	map.value = i;
	map.minv = 2;
	map.maxv = infos->value.max_iter;
	map.mint = 0;
	map.maxt = 1;
	hsv = ft_hsv_for_cid(infos, i, map);
	if (i == infos->value.max_iter && (x + y * infos->width >= 0
			&& x + y * infos->width < infos->height * infos->width))
		infos->img[(int)x + (int)y * infos->width] = 0x000000;
	else if (infos->value.cid == 4)
		infos->img[(int)x + (int)y * infos->width] = ft_get_col(infos
			, ft_hsv2rgb(hsv));
	else
		infos->img[(int)x + (int)y * infos->width] = ft_hsv2rgb(hsv);
	return (infos);
}

t_window		*ft_color(t_window *infos)
{
	if (infos->value.cid == 4)
		infos->value.cid = 1;
	else if (infos->value.cid >= 1)
		infos->value.cid++;
	return (infos);
}

int				ft_create_rgb(double r, double g, double b)
{
	int	ret;

	ret = ((int)b << 0) | ((int)g << 8) | ((int)r << 16);
	return (ret);
}

int				ft_hsv2rgb(t_hsv hsv)
{
	int		i;
	float	f;
	float	p;
	float	q;
	float	t;

	hsv.h = (hsv.h == 360) ? 0 : hsv.h / 60.0f;
	i = (int)hsv.h;
	f = hsv.h - i;
	p = hsv.v * (1.0f - hsv.s) * 255;
	q = hsv.v * (1.0f - (hsv.s * f)) * 255;
	t = hsv.v * (1.0f - (hsv.s * (1.0 - f))) * 255;
	if (i == 0)
		return (ft_create_rgb(hsv.v * 255, t, p));
	else if (i == 1)
		return (ft_create_rgb(q, hsv.v * 255, p));
	else if (i == 2)
		return (ft_create_rgb(p, hsv.v * 255, t));
	else if (i == 3)
		return (ft_create_rgb(p, q, hsv.v * 255));
	else if (i == 4)
		return (ft_create_rgb(t, p, hsv.v * 255));
	return (ft_create_rgb(hsv.v * 255, p, q));
}
