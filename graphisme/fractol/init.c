/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:04:40 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/20 17:40:31 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*ft_init_mandel(t_window *infos)
{
	infos->value.max_iter = 75;
	infos->value.degre = 100;
	infos->value.zmx1 = infos->width / 4;
	infos->value.zmx2 = 2;
	infos->value.zmy1 = infos->height / 4;
	infos->value.zmy2 = 2;
	infos->value.mult = 1;
	infos->value.z = 2;
	infos->value.degre = 100;
	infos->value.dx = 0;
	infos->value.dy = 0;
	return (infos);
}

t_window	*ft_init_julia(t_window *infos)
{
	infos->value.max_iter = 60;
	infos->value.mult = 1;
	infos->value.zoom = 0.80;
	infos->value.degre = 100;
	infos->value.mvx = 0;
	infos->value.mvy = 0;
	infos->cursor.x = 0;
	infos->cursor.y = 0;
	infos->value.lock = 1;
	infos->value.lastcr = 73;
	infos->value.lastci = 280;
	return (infos);
}

t_window	*ft_init_bship(t_window *infos)
{
	infos->value.max_iter = 75;
	infos->value.mult = 1;
	infos->value.zoom = 220;
	infos->value.x1 = 1.6;
	infos->value.y1 = 1.8;
	infos->value.degre = 100;
	infos->value.zmx1 = infos->width / 4;
	infos->value.zmx2 = 2;
	infos->value.zmy1 = infos->height / 4;
	infos->value.zmy2 = 2;
	infos->value.z = 2;
	infos->value.dx = 0;
	infos->value.dy = 0;
	return (infos);
}

static void	ft_init_slide(t_window *infos)
{
	infos->stock_s.slide1.x = 480;
	infos->stock_s.slide1.y = 25;
	infos->stock_s.slide2.x = 480;
	infos->stock_s.slide2.y = 25;
	infos->stock_s.slide3.x = 480;
	infos->stock_s.slide3.y = 50;
	infos->stock_s.slide4.x = 480;
	infos->stock_s.slide4.y = 75;
	infos->stock_s.slide1.col_s.h = 360;
	infos->stock_s.slide1.col_s.s = 1.0;
	infos->stock_s.slide1.col_s.v = 1.0;
	infos->stock_s.slide2.col_s.h = 360;
	infos->stock_s.slide2.col_s.s = 1.0;
	infos->stock_s.slide2.col_s.v = 1.0;
	infos->stock_s.slide3.col_s.h = 360;
	infos->stock_s.slide3.col_s.s = 1.0;
	infos->stock_s.slide3.col_s.v = 1.0;
	infos->stock_s.slide4.col_s.h = 360;
	infos->stock_s.slide4.col_s.s = 1.0;
	infos->stock_s.slide4.col_s.v = 1.0;
	ft_init_slide2(infos);
}

t_window	*ft_init(t_window *infos)
{
	if (infos->fid == 1)
		infos = ft_init_mandel(infos);
	if (infos->fid == 2)
		infos = ft_init_julia(infos);
	if (infos->fid == 3)
		infos = ft_init_bship(infos);
	ft_init_slide(infos);
	return (infos);
}
