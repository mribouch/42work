/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:52:42 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/24 15:30:02 by mribouch         ###   ########.fr       */
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
	ft_putmenu(infos);
	return (0);
}

int			ft_dealkey(int key, t_window *infos)
{
	if (key == 53)
	{
		mlx_destroy_image(infos->mlx_ptr, infos->img_ptr);
		mlx_destroy_window(infos->mlx_ptr, infos->win_ptr);
		free(infos);
		exit(0);
	}
	ft_change_stat(infos, key);
	ft_move_julia(infos, key);
	ft_change_id(infos, key);
	if (key == 15)
		ft_init(infos);
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_lfract(infos);
	ft_putmenu(infos);
	return (0);
}

int			ft_get_cursor(int x, int y, t_window *infos)
{
	infos->cursor.x = x;
	infos->cursor.y = y;
	ft_bzero(infos->img, (infos->height * infos->width));
	ft_lfract(infos);
	ft_putmenu(infos);
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
