/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:08:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/10 16:33:10 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fullcircle(t_window *infos, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	while (r >= 0)
	{
		x = 0;
		y = r;
		d = r - 1;
		while (y >= x)
		{
			infos->img[(xc + x) + (yc + y) * infos->width] = color;
			infos->img[(xc + y) + (yc + x) * infos->width] = color;
			infos->img[(xc - x) + (yc + y) * infos->width] = color;
			infos->img[(xc - y) + (yc + x) * infos->width] = color;
			infos->img[(xc + x) + (yc - y) * infos->width] = color;
			infos->img[(xc + y) + (yc - x) * infos->width] = color;
			infos->img[(xc - x) + (yc - y) * infos->width] = color;
			infos->img[(xc - y) + (yc - x) * infos->width] = color;
			if (d >= 2 * x)
			{
				d -= 2 * x + 1;
				x++;
			}
			else if (d < 2 * (r - y))
			{
				d += 2 * y - 1;
				y--;
			}
			else
			{
				d += 2 * (y - x - 1);
				y--;
				x++;
			}
		}
		r--;
	}
}

void		ft_circle(t_window *infos, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		infos->img[(xc + x) + (yc + y) * infos->width] = color;
		infos->img[(xc + y) + (yc + x) * infos->width] = color;
		infos->img[(xc - x) + (yc + y) * infos->width] = color;
		infos->img[(xc - y) + (yc + x) * infos->width] = color;
		infos->img[(xc + x) + (yc - y) * infos->width] = color;
		infos->img[(xc + y) + (yc - x) * infos->width] = color;
		infos->img[(xc - x) + (yc - y) * infos->width] = color;
		infos->img[(xc - y) + (yc - x) * infos->width] = color;
		if (d >= 2 * x)
		{
			d -= 2 * x + 1;
			x++;
		}
		else if (d < 2 * (r - y))
		{
			d += 2 * y - 1;
			y--;
		}
		else
		{
			d += 2 * (y - x - 1);
			y--;
			x++;
		}
	}
}

double		ft_map(t_mapjs map)
{
	double	rangev;
	double	ranget;
	double	ret;
	double percv;
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
	double percv;
	double	valuet;

	map.value = map.value - map.minv;
	rangev = map.maxv - map.minv;
	ranget = map.maxt - map.mint;
	percv = (100 * map.value) / rangev;
	valuet = ranget * (percv / 100);
	ret = map.mint + valuet;
	return (ret);
}
