/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:53:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:43 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

t_window	*ft_zoom_mandel(t_window *infos, int x, int y)
{
	infos->value.dx = infos->value.dx + x - (infos->width / 2);
	infos->value.dy = infos->value.dy + y - (infos->height / 2) ;
	infos->value.zmx1 *= infos->value.z;
	infos->value.zmx2 *= (1 / infos->value.z);
	infos->value.zmy1 *= infos->value.z;
	infos->value.zmy2 *= (1 / infos->value.z);
	infos->value.dx *= infos->value.z; //- infos->value.lx - x;
	infos->value.dy *= infos->value.z; //- infos->value.ly - y;
	infos->value.max_iter++;
	infos->value.c++;
	infos->value.lx = x;
	infos->value.ly = y;
	return (infos);
}

t_window	*ft_dezoom_mandel(t_window *infos, int x, int y)
{
	infos->value.c--;
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