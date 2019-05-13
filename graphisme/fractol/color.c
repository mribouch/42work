/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:52:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/10 16:33:37 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_window	*ft_fill_imgcolor(t_window *infos, int i, double x, double y)
{
	t_hsv	hsv;
	t_mapjs	map;

	map.value = i;
	map.minv = 2;
	map.maxv = infos->value.max_iter;
	map.mint = 0;
	map.maxt = 1;
	if (infos->value.cid == 1)
	{
		hsv.h = i * 360 / infos->value.degre % 360;
		hsv.s = 1.0;
		hsv.v = 1.0;
	}
	else if (infos->value.cid == 2)
	{
		hsv.h = infos->value.colorh.h;
		hsv.s = ft_map(map);
		hsv.v = 1.0;
	}
	else if (infos->value.cid == 3)
	{
		hsv.h = infos->value.colorh.h;
		hsv.s = 1.0;
		hsv.v = ft_map(map);
	}
	if (i == infos->value.max_iter && (x + y * infos->width >= 0
			&& x + y * infos->width < infos->height * infos->width))
				infos->img[(int)x + (int)y * infos->width] = 0x000000;
		else
			infos->img[(int)x + (int)y * infos->width] = ft_hsv2rgb(hsv);
	return (infos);
}

t_window	*ft_color(t_window *infos)
{
	if (infos->value.cid == 3)
		infos->value.cid = 1;
	else if (infos->value.cid >= 1)
		infos->value.cid++;
	return (infos);
}

int		ft_create_rgb(double r, double g, double b)
{
	int	ret;

	ret = ((int)b << 0) | ((int)g << 8) | ((int)r << 16);
	return (ret);
}

int		ft_hsv2rgb(t_hsv hsv)
{
	int		i;
    float	f;
    float	p;
    float	q;
    float	t;

    if (hsv.s == 0.0f)
        return (ft_create_rgb(hsv.v, hsv.v, hsv.v));
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
