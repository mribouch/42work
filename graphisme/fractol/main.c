/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:28:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/23 13:58:30 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_lfract(t_window *infos)
{
	if (infos->fid == 1)
		ft_mandel(infos);
	else if (infos->fid == 2)
		ft_julia(infos);
	else if (infos->fid == 3)
		ft_bship(infos);
	return (0);
}

int				*ft_get_img(int *img, void *img_ptr, t_window *infos)
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
	infos->win_ptr = mlx_new_window(infos->mlx_ptr, 600, 600, "fractol");
	infos->img = NULL;
	infos->img_ptr = mlx_new_image(infos->mlx_ptr, 600, 600);
	infos->img = ft_get_img(infos->img, infos->img_ptr, infos);
	infos->value.cid = 1;
	infos->btnp = 0;
	infos->value.colorh.h = 360;
	infos->value.colorh.s = 1.0;
	infos->value.colorh.v = 1.0;
	infos->value.lastx = 480;
	infos->value.lasty = 25;
	infos->value.h = 1;
	return (infos);
}

static int		ft_choose_fract(int fid, char *str)
{
	if (ft_strcmp(str, "1") == 0)
		fid = 1;
	else if (ft_strcmp(str, "2") == 0)
		fid = 2;
	else if (ft_strcmp(str, "3") == 0)
		fid = 3;
	return (fid);
}

int				main(int ac, char **av)
{
	t_window	*infos;

	if (ac != 2 || (ft_strcmp(av[1], "1") && ft_strcmp(av[1], "2")
		&& ft_strcmp(av[1], "3")))
	{
		ft_putendl("Usage : ./fractol Fractal\n./fractol 1 (Mandelbrot)");
		ft_putendl("./fractol 2 (Julia)\n./fractol 3 (BurningShip)");
	}
	else
	{
		if (!(infos = malloc(sizeof(t_window))))
			return (0);
		ft_putendl(av[1]);
		infos = ft_fill_infos(infos);
		infos->fid = ft_choose_fract(infos->fid, av[1]);
		infos = ft_init(infos);
		ft_lfract(infos);
		ft_putmenu(infos);
		mlx_hook(infos->win_ptr, 2, (1L << 0), ft_dealkey, infos);
		mlx_hook(infos->win_ptr, 6, (1L << 6), ft_get_cursor, infos);
		mlx_hook(infos->win_ptr, 4, (1L << 2), ft_dealmouse, infos);
		mlx_hook(infos->win_ptr, 5, (1L << 3), ft_check_button, infos);
		mlx_loop(infos->mlx_ptr);
	}
	return (0);
}
