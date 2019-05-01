/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:52:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:34 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>


#include <stdio.h>

t_window	*ft_fill_imgcolor(t_window *infos, int i, double x, double y)
{
	t_hsv	hsv;

	hsv.h = i * 360 / infos->value.degre % 360;
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

int		ft_color(t_window *infos, int i, int color1)
{
	t_color	c1;
	int		ret;

	c1.r = (color1 & 0xFF0000) >> 16;
	c1.g = (color1 & 0x00FF00) >> 8;
	c1.b = (color1 & 0x0000FF);
	//c1.g = i * 255 / infos->value.max_iter;
	c1.r = i * 255 / infos->value.max_iter;
	//c1.b = i * 255 / infos->value.max_iter;
	ret = (c1.b << 0) | (c1.g << 8) | (c1.r << 16);
	return (ret);
}

int		ft_create_rgb(double r, double g, double b)
{
	int	ret;

	//printf("r = %f, g = %f, b = %f\n", r, g, b);
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
