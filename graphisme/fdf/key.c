/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:50:01 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/28 18:09:50 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>
#include <stdio.h>

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
	if (key == 91 || key == 87 || key == 88 ||
		key == 86 || key == 92 || key == 89)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (key == 91)
			infos->state->rota.x += 0.1f;
		else if (key == 87)
			infos->state->rota.x -= 0.1f;
		else if (key == 88)
			infos->state->rota.y += 0.1f;
		else if (key == 86)
			infos->state->rota.y -= 0.1f;
		else if (key == 92)
			infos->state->rota.z -= 0.1f;
		else if (key == 89)
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
	if (key == 123 || key == 124 || key == 126 || key == 125 ||
		key == 1 || key == 13)
	{
		ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
		if (key == 123)
			infos->state->pos.x -= 5;
		else if (key == 124)
			infos->state->pos.x += 5;
		else if (key == 126)
			infos->state->pos.y -= 5;
		else if (key == 125)
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
	static clock_t	last_time = 0.0;
	char			*fps;

	fps = NULL;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
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
	asprintf(&fps, "%.2f", 1 / ((double)(clock() - last_time) / CLOCKS_PER_SEC));
	mlx_string_put(infos->mlx_ptr, infos->win_ptr, 20, 300, 0xFFFFFF, "FPS: ");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 70, 300, 0xFFFFFF, fps);
    free(fps);
    last_time = clock();
	return (0);
}
