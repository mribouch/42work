/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:12:42 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/28 17:35:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point	*ft_isov(t_window *infos)
{
	t_mat4	rot;
	t_mat4	rot2;

	rot = (t_mat4)(struct s_mat4_data) {
		cos(0.785398), -sin(0.785398), 0, 0,
		sin(0.785398), cos(0.785398), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	rot2 = (t_mat4)(struct s_mat4_data) {
		1, 0, 0, 0,
		0, cos(0.523599), -sin(0.523599), 0,
		0, sin(0.523599), cos(0.523599), 0,
		0, 0, 0, 1
	};
	infos->iso = ft_multmat(infos, rot);
	infos->iso = ft_multmat(infos, rot2);
	return (infos->iso);
}

t_point	*ft_persp(t_window *infos, float fov)
{
	int	i;

	i = 0;
	while (i < infos->mapinf->width * infos->mapinf->height)
	{
		if (infos->iso[i].z != 0)
		{
			infos->iso[i].x /= fabsf(infos->iso[i].z) / fov;
			infos->iso[i].y /= fabsf(infos->iso[i].z) / fov;
		}
		infos->iso[i].z *= -1;
		i++;
	}
	return (infos->iso);
}

t_point	*ft_changestat_pos(t_window *infos)
{
	int	i;

	i = 0;
	while (i < infos->mapinf->width * infos->mapinf->height)
	{
		infos->iso[i].x += infos->state->pos.x;
		infos->iso[i].y += infos->state->pos.y;
		infos->iso[i].z += infos->state->pos.z;
		i++;
	}
	return (infos->iso);
}

t_point	*ft_changestat_size(t_window *infos)
{
	int	i;

	i = 0;
	while (i < infos->mapinf->width * infos->mapinf->height)
	{
		infos->iso[i].x = infos->vertices[i].x * infos->state->size.x;
		infos->iso[i].y = infos->vertices[i].y * infos->state->size.y;
		infos->iso[i].z = infos->vertices[i].z * infos->state->size.z;
		i++;
	}
	return (infos->iso);
}

void	ft_callback(t_window *infos)
{
	int i;

	i = 0;
	infos->iso = ft_changestat_size(infos);
	infos->iso = ft_rotx(infos);
	infos->iso = ft_roty(infos);
	infos->iso = ft_rotz(infos);
	if (infos->boolp == 0)
		infos->iso = ft_isov(infos);
	infos->iso = ft_changestat_pos(infos);
	if (infos->boolp == 1)
	{
		infos->iso = ft_persp(infos, 500.0f);
		ft_draw_persp(infos);
	}
	else if (infos->boolp == 0)
		ft_draw_iso(infos);
	mlx_put_image_to_window(infos->mlx_ptr,
		infos->win_ptr, infos->img_ptr, 0, 0);
	ft_putmenu(infos);
}
