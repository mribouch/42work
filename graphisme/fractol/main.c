/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:28:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/08 13:24:11 by mribouch         ###   ########.fr       */
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
	infos->height = 600;
	infos->width = 600;
	infos->win_ptr = mlx_new_window(infos->mlx_ptr, 600, 600, "testwin");
	infos->img = NULL;
	infos->img_ptr = mlx_new_image(infos->mlx_ptr, 600, 600);
	infos->img = ft_get_img(infos->img, infos->img_ptr, infos);
	// infos->value.max_iter = 75;
	// infos->value.zmx1 = infos->width / 4;
	// infos->value.zmx2 = 2;
	// infos->value.zmy1 = infos->height / 4;
	// infos->value.zmy2 = 2;
	// infos->value.zoom = 1;
	// infos->value.mult = 1;
	// infos->value.z = 2;
	// infos->value.degre = 100;
	// infos->value.c = 1;
	// infos->value.lx = 0;
	// infos->value.ly = 0;
	// infos->value.mvx = 0;
	// infos->value.mvy = 0;
	// infos->value.dx = 0;
	// infos->value.dy = 0;
	// infos->cursor.x = 0.285;
	// infos->cursor.y = 0.013;
	// infos->value.lock = 1;
	ft_putendl("la ");
	return (infos);
}

int	main(int ac, char **av)
{
	t_window	*infos;
	if (ac != 2 || (ft_strcmp(av[1], "1") && ft_strcmp(av[1], "2") && ft_strcmp(av[1], "3")))
	{
		ft_putendl("Usage : ./fractol Fractal");
		ft_putendl("./fractol 1 (Mandelbrot)\n./fractol 2 (Julia)");
	}
	else
	{
		if (!(infos = malloc(sizeof(t_window))))
			return (0);
		ft_putendl(av[1]);
		infos = ft_fill_infos(infos);
		if (ft_strcmp(av[1], "1") == 0)
			infos->fid = 1;
		else if (ft_strcmp(av[1], "2") == 0)
			infos->fid = 2;
		else if (ft_strcmp(av[1], "3") == 0)
			infos->fid = 3;
		infos = ft_init(infos);
		ft_lfract(infos);
		//mlx_key_hook(infos->win_ptr, ft_dealkey, infos);
		mlx_hook(infos->win_ptr, 2, (1L << 0), ft_dealkey, infos);
		mlx_hook(infos->win_ptr, 6, (1L << 6), ft_get_cursor, infos);
		mlx_mouse_hook(infos->win_ptr, ft_dealmouse, infos);
		//mlx_loop_hook(infos->mlx_ptr, ft_lfract, infos);
		mlx_loop(infos->mlx_ptr);
		//ft_putendl("what");
	}
	return (0);
}

//http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html
// https://stackoverflow.com/questions/4405381/how-to-zoom-mandelbrot-set