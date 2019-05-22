/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:08:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 12:53:55 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
