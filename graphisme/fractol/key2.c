/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:50:03 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/20 16:13:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_stat(t_window *infos, int key)
{
	if (key == 126)
		infos->value.max_iter += 1 * infos->value.mult;
	if (key == 125 && infos->value.max_iter > 1)
		infos->value.max_iter -= 1 * infos->value.mult;
	if (key == 24)
		infos->value.degre++;
	if (key == 69)
		infos->value.mult++;
	if (key == 78 && infos->value.mult > 1)
		infos->value.mult--;
	if (key == 27 && infos->value.degre > 1)
		infos->value.degre--;
}

void	ft_move_julia(t_window *infos, int key)
{
	if (key == 13)
		infos->value.mvy = infos->value.mvy + 0.1 / infos->value.zoom;
	if (key == 1)
		infos->value.mvy = infos->value.mvy - 0.1 / infos->value.zoom;
	if (key == 0)
		infos->value.mvx = infos->value.mvx + 0.1 / infos->value.zoom;
	if (key == 2)
		infos->value.mvx = infos->value.mvx - 0.1 / infos->value.zoom;
}

void	ft_change_id(t_window *infos, int key)
{
	if (key == 8)
		infos = ft_color(infos);
	if (key == 4)
	{
		if (infos->value.h == 1)
			infos->value.h = 0;
		else
			infos->value.h++;
	}
	if (key == 37)
	{
		if (infos->value.lock == 0)
			infos->value.lock++;
		else if (infos->value.lock == 1)
			infos->value.lock = 0;
	}
}
