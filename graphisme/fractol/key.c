/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:52:42 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/25 16:05:23 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_dealmouse(int button, int x, int y, t_window *infos)
{
	// ft_putnbr(button);
	ft_putstr("x = ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 1)
	{
		// infos->point.minx = -x / infos->value.zoom;
		// infos->point.maxx = -x / infos->value.zoom;
		// infos->point.miny = -y / infos->value.zoom;
		// infos->point.maxy = -y / infos->value.zoom;
		;
	}
	if (button == 5)
	{
		//infos->value.zoom *= 1.05;
		infos->value.dx = infos->value.dx + x - (infos->width / 2);
		infos->value.dy = infos->value.dy + y - (infos->height / 2);
		infos->value.zmx1 *= infos->value.z;
		infos->value.zmx2 *= (1 / infos->value.z);
		infos->value.zmy1 *= infos->value.z;
		infos->value.zmy2 *= (1 / infos->value.z);
		infos->value.dx *= infos->value.z;
		infos->value.dy *= infos->value.z;
		infos->value.max_iter++;
	}
	if (button == 4)
	{
		infos->value.dx = infos->value.dx - x + (infos->width / 2);
		infos->value.dy = infos->value.dy - y + (infos->height / 2);
		infos->value.zmx1 /= infos->value.z;
		infos->value.zmx2 /= (1 / infos->value.z);
		infos->value.zmy1 /= infos->value.z;
		infos->value.zmy2 /= (1 / infos->value.z);
		infos->value.dx /= infos->value.z;
		infos->value.dy /= infos->value.z;
	}
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_mandel(infos);
	return (0);
}

int			ft_dealkey(int key, t_window *infos)
{
	// ft_putnbr(key);
	// ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 126)
		infos->value.max_iter += 1;
	if (key == 125 && infos->value.max_iter > 1)
		infos->value.max_iter -= 1;
	if (key == 24)
		;
		//infos->value.zoom *= 1.05;
	if (key == 27)
	;
		//infos->value.zoom /= 1.05;
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_mandel(infos);
	return (0);
}
