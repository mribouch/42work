/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:50:01 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/09 18:05:25 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_persp(int key, t_window *infos)
{
	if (key == 35)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		infos->boolp = !infos->boolp;
		if (infos->boolp == 1)
		{
			infos->state->pos.z -= 150;
			infos->state->rota.x += 1.3f;
		}
		else
		{
			infos->state->pos.z += 150;
			infos->state->rota.x -= 1.3f;
		}
		ft_callback(infos);
	}
}

void	ft_keyrota(int key, t_window *infos)
{
	if (key == 91 || key == 87 || key == 88 || key == 126 || key == 125 ||
		key == 86 || key == 92 || key == 89 || key == 123 || key == 124)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (key == 91 || key == 126)
			infos->state->rota.x += 0.1f;
		else if (key == 87 || key == 125)
			infos->state->rota.x -= 0.1f;
		else if (key == 88)
			infos->state->rota.y += 0.1f;
		else if (key == 86)
			infos->state->rota.y -= 0.1f;
		else if (key == 92 || key == 123)
			infos->state->rota.z -= 0.1f;
		else if (key == 89 || key == 124)
			infos->state->rota.z += 0.1f;
		ft_callback(infos);
	}
}

void	ft_keysize(int key, t_window *infos)
{
	if (key == 24 || key == 27 || key == 69 || key == 78)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (key == 24)
			infos->state->size.z += 0.1f;
		else if (key == 27)
			infos->state->size.z -= 0.1f;
		else if (key == 69)
		{
			infos->state->size.x *= 1.1f;
			infos->state->size.y *= 1.1f;
			infos->state->size.z *= 1.1f;
		}
		else if (key == 78)
		{
			infos->state->size.x /= 1.1f;
			infos->state->size.y /= 1.1f;
			infos->state->size.z /= 1.1f;
		}
		ft_callback(infos);
	}
}

void	ft_keymove(int key, t_window *infos)
{
	if (key == 0 || key == 2 || key == 257 || key == 49 ||
		key == 1 || key == 13 || key == 83 || key == 85)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (key == 2 || key == 83)
			infos->state->pos.x -= 5;
		else if (key == 0 || key == 85)
			infos->state->pos.x += 5;
		else if (key == 257)
			infos->state->pos.y -= 5;
		else if (key == 49)
			infos->state->pos.y += 5;
		else if (key == 1)
			infos->state->pos.z -= 5;
		else if (key == 13)
			infos->state->pos.z += 5;
		ft_callback(infos);
	}
}

int		ft_dealkey(int key, t_window *infos)
{
	if (key == 53)
	{
		ft_free_infos(infos);
		exit(0);
	}
	ft_keymove(key, infos);
	ft_keysize(key, infos);
	ft_keyrota(key, infos);
	ft_set_persp(key, infos);
	ft_set_color(key, infos);
	if (key == 15)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (infos->boolp == 0)
			infos->state = ft_fill_state(infos->state);
		else
			infos->state = ft_fill_persp_state(infos->state);
		ft_callback(infos);
	}
	return (0);
}
