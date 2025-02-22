/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:53:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/23 13:46:41 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*ft_zoom_mandel(t_window *infos, int x, int y)
{
	infos->value.dx = infos->value.dx + x - (infos->width / 2);
	infos->value.dy = infos->value.dy + y - (infos->height / 2);
	infos->value.zmx1 *= infos->value.z;
	infos->value.zmx2 *= (1 / infos->value.z);
	infos->value.zmy1 *= infos->value.z;
	infos->value.zmy2 *= (1 / infos->value.z);
	infos->value.dx *= infos->value.z;
	infos->value.dy *= infos->value.z;
	infos->value.max_iter++;
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
	infos->value.max_iter--;
	return (infos);
}
