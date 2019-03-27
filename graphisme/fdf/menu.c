/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:51:39 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/27 14:43:35 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putrotate(t_window *i, int c)
{
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 860, c,
		"Rotate X up    : Num 8");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 880, c,
		"Rotate X down  : Num 5");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 900, c,
		"Rotate Y right : Num 6");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 920, c,
		"Rotate Y left  : Num 4");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 940, c,
		"Rotate Z right : Num 9");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 960, c,
		"Rotate Z left  : Num 7");
}

void	ft_putsize(t_window *i, int c)
{
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 10, c,
		"Zoom In  : Num +");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 30, c,
		"Zoom Out : Num -");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 50, c,
		"More altitude : +");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 70, c,
		"Less altitude : -");
}

void	ft_putmove(t_window *i, int c)
{
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 10, c,
		"Move right     : Right arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 30, c,
		"Move left      : Left arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 50, c,
		"Move up        : Up arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 70, c,
		"Move down      : Down arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 70, c,
		"Move down      : Down arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 90, c,
		"Move frontward : Page up (Perspective view)");
}

void	ft_putmenu(t_window *i)
{
	int	c;

	c = 0x5995DA;
	ft_putmove(i, c);
	ft_putsize(i, c);
	ft_putrotate(i, c);
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 920, c,
		"Reset the map           : r");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 940, c,
		"Change Background Color : c");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 960, c,
		"Perspective view        : p");
}
