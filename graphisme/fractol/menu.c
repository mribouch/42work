/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:25:12 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 12:13:41 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_hsv	ft_get_h(t_window *infos, int x, int y, int length)
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

t_window		*ft_putrgbar(t_window *infos, int x, int y, int length)
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

int				ft_in_bar(t_window *infos, int x, int y, int length)
{
	if ((infos->cursor.x >= x && infos->cursor.x <= x + length)
		&& (infos->cursor.y >= y - 5 && infos->cursor.y <= y + 9))
		return (1);
	return (0);
}

t_window		*ft_put_slide_hsv(t_window *infos, int x, int y)
{
	t_point	c;

	c.x = infos->cursor.x;
	c.y = y + 2;
	infos = ft_putrgbar(infos, x, y, 100);
	infos = ft_putrgbar(infos, x, y + 1, 100);
	infos = ft_putrgbar(infos, x, y + 2, 100);
	infos = ft_putrgbar(infos, x, y + 3, 100);
	infos = ft_putrgbar(infos, x, y + 4, 100);
	if (infos->btnp == 1 && ft_in_bar(infos, x, y, 100) == 1)
	{
		infos->value.colorh = ft_get_h(infos, x, y, 100);
		ft_circle(infos, c, 7, 0x000000);
		ft_fullcircle(infos, c, 6, ft_hsv2rgb(infos->value.colorh));
		infos->value.lastx = infos->cursor.x;
	}
	else
	{
		c.x = infos->value.lastx;
		ft_circle(infos, c, 7, 0x000000);
		ft_fullcircle(infos, c, 6, ft_hsv2rgb(infos->value.colorh));
	}
	return (infos);
}

t_window		*ft_putmenu(t_window *infos)
{
	int		c;
	void	*m;
	void	*w;

	m = infos->mlx_ptr;
	w = infos->win_ptr;
	if (infos->value.h == 1)
	{
		if (infos->value.cid == 3)
			c = 0xFFFFFF;
		else
			c = 0x000000;
		mlx_string_put(m, w, 10, 10, c, "Hide menu = 'h'");
		mlx_string_put(m, w, 10, 30, c, "Reset = 'r'");
		mlx_string_put(m, w, 10, 50, c, "Zoom = Scroll");
		mlx_string_put(m, w, 10, 70, c, "Change color mode = 'c'");
		mlx_string_put(m, w, 10, 90, c, "Increase iteration = Up arrow");
		mlx_string_put(m, w, 10, 110, c, "Decrease iteration = Down arrow");
		mlx_string_put(m, w, 10, 130, c, "Move Julia  = w, a, s, d");
		mlx_string_put(m, w, 10, 150, c, "Lock Julia  = 'l'");
		mlx_string_put(m, w, 10, 540, c, "Spread of color = '-', '+'");
		mlx_string_put(m, w, 10, 560, c, "Increase multiply iteration = Num +");
		mlx_string_put(m, w, 10, 580, c, "Decrease multiply iteration = Num -");
	}
	return (infos);
}
