/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:53:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/10 16:35:47 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*ft_zoom_bship(t_window *infos, double x, double y)
{
	infos->value.x1 = (x / infos->value.zoom + infos->value.x1)
		- (x / infos->value.zoom * 1.3);
	infos->value.y1 = (y / infos->value.zoom + infos->value.y1)
		- (y / infos->value.zoom * 1.3);
	infos->value.zoom *= 1.3;
	infos->value.max_iter++;
	return (infos);
}

t_window	*ft_dezoom_bship(t_window *infos, double x, double y)
{
	infos->value.x1 = (x / infos->value.zoom + infos->value.x1)
		- (x / infos->value.zoom / 1.3);
	infos->value.y1 = (y / infos->value.zoom + infos->value.y1)
		- (y / infos->value.zoom / 1.3);
	infos->value.zoom /= 1.3;
	infos->value.max_iter++;
	return (infos);
}

t_window	*ft_zoom_mandel(t_window *infos, int x, int y)
{
	infos->value.dx = infos->value.dx + x - (infos->width / 2);
	infos->value.dy = infos->value.dy + y - (infos->height / 2) ;
	infos->value.zmx1 *= infos->value.z;
	infos->value.zmx2 *= (1 / infos->value.z);
	infos->value.zmy1 *= infos->value.z;
	infos->value.zmy2 *= (1 / infos->value.z);
	infos->value.dx *= infos->value.z;
	infos->value.dy *= infos->value.z;
	infos->value.max_iter++;
	infos->value.lx = x;
	infos->value.ly = y;
	return (infos);
}

t_window	*ft_dezoom_mandel(t_window *infos, int x, int y)
{
	infos->value.dx = infos->value.dx - x + (infos->width / 2);
	infos->value.dy = infos->value.dy - y + (infos->height / 2);
	infos->value.zmx1 /= infos->value.z;
	infos->value.zmx2 /= (1 / infos->value.z);
	infos->value.zmy1 /= infos->value.z;
	infos->value.zmy2 /= (1 / infos->value.z);
	infos->value.dx /= infos->value.z;
	infos->value.dy /= infos->value.z;
	infos->value.lx = x;
	infos->value.ly = y;
	infos->value.max_iter--;
	return (infos);
}