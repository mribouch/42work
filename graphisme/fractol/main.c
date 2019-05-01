/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:28:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:35 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

int			*ft_get_img(int *img, void *img_ptr, t_window *infos)
{
	int bpp;
	int s_l;
	int endian;

	img = (int*)mlx_get_data_addr(img_ptr, &bpp, &s_l, &endian);
	ft_bzero(img, infos->width * infos->height);
	return (img);
}

static t_window	*ft_fill_infos(t_window *infos)
{
	infos->mlx_ptr = mlx_init();
	infos->height = 800;
	infos->width = 800;
	infos->win_ptr = mlx_new_window(infos->mlx_ptr, 800, 800, "testwin");
	infos->img = NULL;
	infos->img_ptr = mlx_new_image(infos->mlx_ptr, 800, 800);
	infos->img = ft_get_img(infos->img, infos->img_ptr, infos);
	infos->value.max_iter = 50;
	infos->value.zmx1 = infos->width / 4;
	infos->value.zmx2 = 2;
	infos->value.zmy1 = infos->height / 4;
	infos->value.zmy2 = 2;
	infos->value.zoom = 1;
	infos->value.mult = 1;
	infos->value.z = 2;
	infos->value.degre = 100;
	infos->value.c = 1;
	infos->value.lx = 0;
	infos->value.ly = 0;
	infos->value.mvx = 0;
	infos->value.mvy = 0;
	infos->value.dx = 0;
	infos->value.dy = 0;
	ft_putendl("la ");
	return (infos);
}

int	main(int ac, char **av)
{
	t_window	*infos;
	if (ac != 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")))
	{
		ft_putendl("Usage : ./fractol Fractal");
		ft_putendl("./fractol Mandelbrot\n./fractal Julia");
	}
	else
	{
		if (!(infos = malloc(sizeof(t_window))))
			return (0);
		ft_putendl(av[1]);
		infos = ft_fill_infos(infos);
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			infos->fid = 1;
		else if (ft_strcmp(av[1], "Julia") == 0)
			infos->fid = 2;
		ft_lfract(infos);
		mlx_hook(infos->win_ptr, 2, (1L << 0), ft_dealkey, infos);
		mlx_mouse_hook(infos->win_ptr, ft_dealmouse, infos);
		//mlx_loop_hook(infos->mlx_ptr, ft_lfract, infos);
		mlx_loop(infos->mlx_ptr);
		//ft_putendl("what");
	}
	return (0);
}

//http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
// https://stackoverflow.com/questions/4405381/how-to-zoom-mandelbrot-set