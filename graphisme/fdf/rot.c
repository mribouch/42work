/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:31:31 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/27 17:02:35 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point	*ft_multmat(t_window *infos, t_mat4 rot)
{
	int		i;
	float	x;
	float	y;
	float	z;

	i = 0;
	while (i < infos->mapinf->height * infos->mapinf->width)
	{
		x = rot.d.m00 * infos->iso[i].x + rot.d.m01 * infos->iso[i].y +
			rot.d.m02 * infos->iso[i].z + rot.d.m03 * 1;
		y = rot.d.m10 * infos->iso[i].x + rot.d.m11 * infos->iso[i].y +
			rot.d.m12 * infos->iso[i].z + rot.d.m13 * 1;
		z = rot.d.m20 * infos->iso[i].x + rot.d.m21 * infos->iso[i].y +
			rot.d.m22 * infos->iso[i].z + rot.d.m23 * 1;
		infos->iso[i].x = x;
		infos->iso[i].y = y;
		infos->iso[i].z = z;
		i++;
	}
	return (infos->iso);
}

t_point	*ft_rotx(t_window *infos)
{
	t_mat4	rot;

	rot = (t_mat4)(struct s_mat4_data) {
		1, 0, 0, 0,
		0, cos(infos->state->rota.x), -sin(infos->state->rota.x), 0,
		0, sin(infos->state->rota.x), cos(infos->state->rota.x), 0,
		0, 0, 0, 1
	};
	infos->iso = ft_multmat(infos, rot);
	return (infos->iso);
}

t_point	*ft_roty(t_window *infos)
{
	t_mat4	rot;

	rot = (t_mat4)(struct s_mat4_data) {
		cos(infos->state->rota.y), 0, sin(infos->state->rota.y), 0,
		0, 1, 0, 0,
		-sin(infos->state->rota.y), 0, cos(infos->state->rota.y), 0,
		0, 0, 0, 1
	};
	infos->iso = ft_multmat(infos, rot);
	return (infos->iso);
}

t_point	*ft_rotz(t_window *infos)
{
	t_mat4	rot;

	rot = (t_mat4)(struct s_mat4_data) {
		cos(infos->state->rota.z), sin(infos->state->rota.z), 0, 0,
		-sin(infos->state->rota.z), cos(infos->state->rota.z), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	infos->iso = ft_multmat(infos, rot);
	return (infos->iso);
}
