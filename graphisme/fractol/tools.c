/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:08:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/21 16:09:39 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



#include <stdio.h>

int			ft_get_col(t_window *infos, int color)
{
	float	perr;
	float	perg;
	float	perb;
	t_color	rgb;

	rgb.r = (color & 0xFF0000) >> 16;
	rgb.g = (color & 0x00FF00) >> 8;
	rgb.b = (color & 0x0000FF);
	perr = (float)rgb.r / 255;
	perg = (float)rgb.g / 255;
	perb = (float)rgb.b / 255;
	// printf("col rgb = %X\n", ft_hsv2rgb(infos->stock_s.slide2.col_s));
	return (ft_hsv2rgb(infos->stock_s.slide2.col_s) * perr
		+ ft_hsv2rgb(infos->stock_s.slide3.col_s) * perg
			+ ft_hsv2rgb(infos->stock_s.slide4.col_s) * perb);
}

void		ft_print_sld(t_window *infos)
{
	if (infos->value.cid == 2 || infos->value.cid == 3)
		infos->stock_s.slide1.col_s = ft_put_slide_hsv(infos
			, &infos->stock_s.slide1);
	if (infos->value.cid == 4)
	{
		infos->stock_s.slide2.col_s = ft_put_slide_hsv(infos
			, &infos->stock_s.slide2);
		// printf("col h = %f\n", infos->stock_s.slide2.col_s.h);
		// printf("col s = %f\n", infos->stock_s.slide2.col_s.s);
		// printf("col v = %f\n", infos->stock_s.slide2.col_s.v);
		infos->stock_s.slide3.col_s = ft_put_slide_hsv(infos
			, &infos->stock_s.slide3);
		infos->stock_s.slide4.col_s = ft_put_slide_hsv(infos
			, &infos->stock_s.slide4);
	}
}

void		ft_init_slide2(t_window *infos)
{
	infos->stock_s.slide1.lastx = 480;
	infos->stock_s.slide1.lasty = 25;
	infos->stock_s.slide2.lastx = 480;
	infos->stock_s.slide2.lasty = 25;
	infos->stock_s.slide3.lastx = 480;
	infos->stock_s.slide3.lasty = 25;
	infos->stock_s.slide4.lastx = 480;
	infos->stock_s.slide4.lasty = 25;
}

double		ft_map(t_mapjs map)
{
	double	rangev;
	double	ranget;
	double	ret;
	double	percv;
	double	valuet;

	rangev = map.maxv - map.minv;
	ranget = map.maxt - map.mint;
	percv = (100 * map.value) / rangev;
	valuet = ranget * (percv / 100);
	ret = map.mint + valuet;
	return (ret);
}

double		ft_map2(t_mapjs map)
{
	double	rangev;
	double	ranget;
	double	ret;
	double	percv;
	double	valuet;

	map.value = map.value - map.minv;
	rangev = map.maxv - map.minv;
	ranget = map.maxt - map.mint;
	percv = (100 * map.value) / rangev;
	valuet = ranget * (percv / 100);
	ret = map.mint + valuet;
	return (ret);
}
