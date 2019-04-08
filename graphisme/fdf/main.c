/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:19:25 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:13 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_window	*ft_create_infos(t_window *infos, int *fd, char **av)
{
	if (!(infos = malloc(sizeof(t_window))))
		return (0);
	if (!(infos->mapinf = malloc(sizeof(t_map))))
	{
		free(infos);
		return (0);
	}
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
	{
		free(infos->vertices);
		return (0);
	}
	if (!(infos->state = malloc(sizeof(t_state))))
	{
		free(infos->vertices);
		free(infos->iso);
		return (0);
	}
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
			ft_free_inmap(infos);
			ft_putendl("Invalid file.");
			exit(0);
		}
		infos = ft_fill_infos_point(infos, col);
		ft_free_dchar(col);
		mlx_hook(infos->win_ptr, 2, 1L << 0, ft_dealkey, infos);
		mlx_loop(infos->mlx_ptr);
	}
}
