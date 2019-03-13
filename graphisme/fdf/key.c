/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:50:01 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/13 17:56:40 by mribouch         ###   ########.fr       */
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
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->size.z += 0.1f;
        ft_callback(infos);
    }
    else if (key == 27)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->size.z -= 0.1f;
        ft_callback(infos);
    }
    // key = <-
    else if (key == 123)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->pos.x -= 5;
        ft_callback(infos);
    }
    else if (key == 124)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->pos.x += 5;
        ft_callback(infos);
    }
    else if (key == 126)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        ft_putendl("DANS KEY :");
        ft_putstr("infos->vertices[30].x = ");
        ft_putnbr(infos->vertices[30].x);
        infos->state->pos.y -= 5;
        ft_callback(infos);
    }
    else if (key == 125)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->pos.y += 5;
        ft_callback(infos);
    }
    else if (key == 69)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->size.x += 0.05f;
        infos->state->size.y += 0.05f;
        infos->state->size.z += 0.05f;
        ft_callback(infos);
    }
    else if (key == 78)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->size.x -= 0.05;
        infos->state->size.y -= 0.05;
        infos->state->size.z -= 0.05;
        ft_callback(infos);
    }
    else if (key == 91)
    {
       // mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.x += 0.01f;
        ft_callback(infos);
    }
    // key = 5
    else if (key == 87)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.x -= 0.01f;
        ft_callback(infos);
    }
    // key = 6
        else if (key == 88)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.y += 0.01f;
        ft_callback(infos);
    }
    // key = 4
    else if (key == 86)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.y -= 0.01f;
        ft_callback(infos);
    }
    // key = 9
    else if (key == 92)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.z += 0.01f;
        ft_callback(infos);
    }
    //key = 7
    else if (key == 89)
    {
        ft_bblue(infos->img, (infos->height * infos->width));
        infos->state->rota.z -= 0.01f;
        ft_callback(infos);
    }
    /*else if (key == 46)
    {
        mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        ft_new(infos);
    }*/
    //(void)infos;
    return (0);
}