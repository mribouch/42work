/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:32:24 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:40 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

//https://lodev.org/cgtutor/juliamandelbrot.html

t_fract	ft_filljulia(t_fract j, double x, double y, t_window *infos)
{
	j.zr = 1.5 * (x - infos->width / 2) / (0.5 * infos->value.zoom * infos->width) + infos->value.mvx;
	j.zi = (y - infos->height / 2) / (0.5 * infos->value.zoom *infos->height) + infos->value.mvy;
	// j.zr = 0;
	// j.zi = 0;
	return (j);
}

int	ft_julia(t_window *infos)
{
	t_fract	j;
	double		oldr;
	double		oldi;
	double		cre;
	double		cim;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	cre = -0.7;
	cim = 0.27015;
	while (x < infos->width)
	{
		while (y < infos->height)
		{
			j = ft_filljulia(j, x, y, infos);
			i = 0;
			while (i < infos->value.max_iter)
			{
				oldr = j.zr;
				oldi = j.zi;
				j.zr = oldr * oldr - oldi * oldi + cre;
				j.zi = 2 * oldr * oldi + cim;
				if (j.zr * j.zr + j.zi * j.zi >= 16)
					break;
				i++;
			}
			infos = ft_fill_imgcolor(infos, i, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
	return (0);
}

//https://stackoverflow.com/questions/34852707/how-do-i-zoom-on-cursor-position-in-mandelbrot-or-julia-set