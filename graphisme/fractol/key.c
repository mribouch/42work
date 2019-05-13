/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:52:42 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/13 13:32:44 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_dealmouse(int button, int x, int y, t_window *infos)
{
	if (button == 1)
	{
		infos->btnp = 1;
	}
	if (button == 5)
	{
		if (infos->fid == 1 || infos->fid == 3)
			infos = ft_zoom_mandel(infos, x, y);
		if (infos->fid == 2)
			infos->value.zoom *= 1.5;
	}
	if (button == 4)
	{
		if (infos->fid == 1 || infos->fid == 3)
			infos = ft_dezoom_mandel(infos, x, y);
		if (infos->fid == 2)
			infos->value.zoom /= 1.5;
	}
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_lfract(infos);
	return (0);
}

int			ft_dealkey(int key, t_window *infos)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 126)
		infos->value.max_iter += 1 * infos->value.mult;
	if (key == 125 && infos->value.max_iter > 1)
		infos->value.max_iter -= 1 * infos->value.mult;
	if (key == 24)
		infos->value.degre++;
	if (key == 69)
		infos->value.mult++;
	if (key == 78)
		infos->value.mult--;
	if (key == 27 && infos->value.degre > 1)
		infos->value.degre--;
	if (key == 13)
		infos->value.mvy = infos->value.mvy + 0.1 / infos->value.zoom;
	if (key == 1)
		infos->value.mvy = infos->value.mvy - 0.1 / infos->value.zoom;
	if (key == 0)
		infos->value.mvx = infos->value.mvx + 0.1 / infos->value.zoom;
	if (key == 2)
		infos->value.mvx = infos->value.mvx - 0.1 / infos->value.zoom;
	if (key == 8)
		infos = ft_color(infos);
	if (key == 37)
	{
		if (infos->value.lock == 0)
			infos->value.lock++;
		else if(infos->value.lock == 1)
			infos->value.lock = 0;
	}
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_lfract(infos);
	return (0);
}

int			ft_get_cursor(int x, int y, t_window *infos)
{
	// if (infos->value.lock == 0)
	// {
		infos->cursor.x = x;
		infos->cursor.y = y;
	//}
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_lfract(infos);
	return (0);
}

int			ft_check_button(int button, int x, int y, t_window *infos)
{
	(void)x;
	(void)y;
	if (button == 1)
		infos->btnp = 0;
	return (0);
}