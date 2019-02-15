/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:50:01 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/13 15:14:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_dealkey(int key, t_window *infos)
{
    ft_putnbr(key);
    ft_putchar('\n');
    if (key == 53)
      exit(0);
    else if (key == 24)
    {
        mlx_clear_window (infos->mlx_ptr, infos->win_ptr);
        infos = ft_more_z(infos);
        ft_draw(infos);
    }
    else if (key == 27)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_less_z(infos);
        ft_draw(infos);
    }
    else if (key == 123)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_left(infos);
        ft_draw(infos);
    }
    else if (key == 124)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_right(infos);
        ft_draw(infos);
    }
    else if (key == 126)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_up(infos);
        ft_draw(infos);
    }
    else if (key == 125)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_down(infos);
        ft_draw(infos);
    }
    else if (key == 69)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_zoom(infos);
        //infos->vertices = ft_get_point(infos->vertices, infos->mapinf, infos->var);
        ft_draw(infos);
    }
    else if (key == 78)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        infos = ft_dezoom(infos);
        //infos->vertices = ft_get_point(infos->vertices, infos->mapinf, infos->var);
        ft_draw(infos);
        ft_putchar('\n');
        ft_putstr("mx = ");
        ft_putnbr(infos->var->mx);
        ft_putchar('\n');
        ft_putstr("my = ");
        ft_putnbr(infos->var->my);
        ft_putchar('\n');
    }
    (void)infos;
    return (0);
}