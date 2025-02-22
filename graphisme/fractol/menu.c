/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 19:25:12 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/24 15:05:31 by mribouch         ###   ########.fr       */
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

static int		ft_in_bar(t_window *infos, int x, int y, int length)
{
	if ((infos->cursor.x >= x && infos->cursor.x <= x + length)
		&& (infos->cursor.y >= y - 5 && infos->cursor.y <= y + 9))
		return (1);
	return (0);
}

t_hsv			ft_put_slide_hsv(t_window *infos, t_slider *slide)
{
	t_point		c;
	t_square	sqw;
	t_square	sqb;

	c.x = infos->cursor.x;
	c.y = slide->y + 2;
	ft_check_square(infos, slide, &sqw, &sqb);
	infos = ft_put_gauge(infos, slide);
	if (infos->btnp == 1 && ft_in_bar(infos, slide->x, slide->y, 100) == 1)
	{
		slide->col_s = ft_get_h(infos, slide->x, slide->y, 100);
		ft_circle(infos, c, 7, 0x000000);
		ft_fullcircle(infos, c, 6, ft_hsv2rgb(slide->col_s));
		slide->lastx = infos->cursor.x;
	}
	else
	{
		c.x = slide->lastx;
		ft_circle(infos, c, 7, 0x000000);
		ft_fullcircle(infos, c, 6, ft_hsv2rgb(slide->col_s));
	}
	return (slide->col_s);
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
		mlx_string_put(m, w, 10, 90, c, "Change iteration = UP/DOWN arrow");
		mlx_string_put(m, w, 10, 110, c, "Move Julia  = w, a, s, d");
		mlx_string_put(m, w, 10, 130, c, "Lock Julia  = 'l'");
		mlx_string_put(m, w, 10, 520, c, "Color's spread in mode 1 = -, +");
		mlx_string_put(m, w, 10, 540, c, "Color's spread in mode 4 = <-/->");
		mlx_string_put(m, w, 10, 560, c, "Multiply iteration = Num + / Num -");
		mlx_string_put(m, w, 350, 580, c, "Switch fractal : 1, 2, 3");
	}
	return (infos);
}
