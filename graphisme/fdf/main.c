/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:19:25 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/22 18:10:44 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*ft_get_img(int *img, void *img_ptr, t_window *infos)
{
	int bpp;
	int s_l;
	int endian;

	img = (int*)mlx_get_data_addr(img_ptr, &bpp, &s_l, &endian);
	ft_bzero(img, infos->width * infos->height);
	return (img);
}

t_state		*ft_fill_state(t_state *state)
{
	state->size.x = 1;
	state->size.y = 1;
	state->size.z = 1;
	state->rota.x = 0;
	state->rota.y = 0;
	state->rota.z = 0;
	state->pos.x = 0;
	state->pos.y = 0;
	state->pos.z = 0;
	return (state);
}

void		ft_putmenu(t_window *i)
{
	int c;

	c = 0x5995DA;
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 10, c, "Move right     : Right arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 30, c, "Move left      : Left arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 50, c, "Move up        : Up arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 70, c, "Move down      : Down arrow");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 90, c, "Move frontward : Page up (Perspective view)");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 110, c, "Move Backward  : Page down (Perspective view)");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 10, c, "Zoom In  : Num +");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 30, c, "Zoom Out : Num -");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 50, c, "More altitude : +");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1300, 70, c, "Less altitude : -");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 940, c, "Change Background Color : c");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 10, 960, c, "Perspective view        : p");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 860, c, "Rotate X up    : Num 8");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 880, c, "Rotate X down  : Num 5");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 900, c, "Rotate Y right : Num 6");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 920, c, "Rotate Y left  : Num 4");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 940, c, "Rotate Z left  : Num 7");
	mlx_string_put(i->mlx_ptr, i->win_ptr, 1220, 960, c, "Rotate Z right : Num 9");
}

t_window	*ft_create_infos(t_window *infos, int *fd, char **av)
{
	if (!(infos = malloc(sizeof(t_window))))
		return (0);
	if (!(infos->mapinf = malloc(sizeof(t_map))))
		return (0);
	*fd = open(av[1], O_RDONLY);
	if (*fd < 0)
	{
		ft_putendl("File does not exist.");
		exit(0);
	}
	return (infos);
}

t_window	*ft_fill_infos_point(t_window *infos, char **col)
{
	if (!(infos->vertices = malloc(sizeof(t_point) *
		(infos->mapinf->width * (infos->mapinf->height)) + 1)))
		return (0);
	if (!(infos->iso = malloc(sizeof(t_point) *
		(infos->mapinf->width * (infos->mapinf->height)) + 1)))
		return (0);
	if (!(infos->state = malloc(sizeof(t_state))))
		return (0);
	infos->state = ft_fill_state(infos->state);
	infos->boolp = 0;
	infos->bcol = 0x000000;
	infos->colid = 0;
	infos->vertices = ft_new(infos, infos->vertices, col);
	infos->iso = ft_new(infos, infos->iso, col);
	ft_callback(infos);
	return (infos);
}

t_window	*ft_fill_infos(t_window *infos)
{
	infos->mlx_ptr = mlx_init();
	infos->height = 1000;
	infos->width = 1500;
	infos->win_ptr = mlx_new_window(infos->mlx_ptr, 1500, 1000, "testwin");
	infos->img = NULL;
	infos->img_ptr = mlx_new_image(infos->mlx_ptr, 1500, 1000);
	infos->img_ptr = infos->img_ptr;
	infos->img = ft_get_img(infos->img, infos->img_ptr, infos);
	return (infos);
}

int			main(int ac, char **av)
{
	int			fd;
	char		**col;
	t_window	*infos;

	if (ac != 2)
		ft_putendl("usage : ./fdf file_name");
	else
	{
		infos = NULL;
		fd = 0;
		infos = ft_create_infos(infos, &fd, av);
		infos = ft_fill_infos(infos);
		if ((infos->mapinf = ft_read(fd, infos->mapinf, &col)) == 0)
		{
			ft_putendl("Invalid file.");
			exit(0);
		}
		infos = ft_fill_infos_point(infos, col);
		mlx_key_hook(infos->win_ptr, ft_dealkey, infos);
		mlx_loop(infos->mlx_ptr);
	}
}
