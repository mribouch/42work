/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:25:12 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/13 16:02:16 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>



t_hsv			ft_get_h(t_window *infos, int x, int y, int length)
{
	t_mapjs	map;
	t_hsv	hsv;

	(void)y;
	hsv.s = 1.0;
	hsv.v = 1.0;
	map.minv = x;
	map.maxv = x + length;
	map.mint = 0;
	map.maxt = 360;
	map.value = infos->cursor.x;
	hsv.h = (int)ft_map2(map);
	return (hsv);
}

t_window	*ft_putrgbar(t_window *infos, int x, int y, int length)
{
	t_mapjs	map;
	t_hsv	hsv;

	hsv.s = 1.0;
	hsv.v = 1.0;
	map.minv = x;
	map.maxv = x + length;
	map.mint = 0;
	map.maxt = 360;
	while (x < map.maxv)
	{
		map.value = x;
		hsv.h = (int)ft_map2(map);
		infos->img[x + y * infos->width] = ft_hsv2rgb(hsv);
		x++;
	}
	return (infos);
}

int			ft_in_bar(t_window *infos, int x, int y, int length)
{
	if ((infos->cursor.x >= x && infos->cursor.x <= x + length)
		&& (infos->cursor.y >= y - 5 && infos->cursor.y <= y + 9))
		return (1);
	return (0);
}

t_window	*ft_put_slide_hsv(t_window *infos, int x, int y)
{
	infos = ft_putrgbar(infos, x, y, 100);
	infos = ft_putrgbar(infos, x, y + 1, 100);
	infos = ft_putrgbar(infos, x, y + 2, 100);
	infos = ft_putrgbar(infos, x, y + 3, 100);
	infos = ft_putrgbar(infos, x, y + 4, 100);
	if (infos->btnp == 1 && ft_in_bar(infos, x, y, 100) == 1)
	{
		infos->value.colorh = ft_get_h(infos, x, y, 100);
		ft_circle(infos, infos->cursor.x, y + 2, 7, 0x000000);
		ft_fullcircle(infos, infos->cursor.x, y + 2, 6, ft_hsv2rgb(infos->value.colorh));
		infos->value.lastx = infos->cursor.x;
	}
	else
	{
		ft_circle(infos, infos->value.lastx, y + 2, 7, 0x000000);
		ft_fullcircle(infos, infos->value.lastx, y + 2, 6, ft_hsv2rgb(infos->value.colorh));
	}
	return (infos);
}

t_window	*ft_putmenu(t_window *infos)
{
	mlx_string_put(infos->mlx_ptr, infos->win_ptr, 100, 100, 0x5995DA,"Zoom = Scroll");
	return (infos);
}