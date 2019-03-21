/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:50:01 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/21 15:47:24 by mribouch         ###   ########.fr       */
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
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->size.z += 0.1f;
        ft_callback(infos);
    }
    else if (key == 27)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->size.z -= 0.1f;
        ft_callback(infos);
    }
    // key = <-
    else if (key == 123)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->pos.x -= 5;
        ft_callback(infos);
    }
    else if (key == 124)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->pos.x += 5;
        ft_callback(infos);
    }
    else if (key == 126)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        //ft_putendl("DANS KEY :");
        //ft_putstr("infos->vertices[30].x = ");
        //ft_putnbr(infos->vertices[30].x);
        infos->state->pos.y -= 5;
        ft_callback(infos);
    }
    else if (key == 125)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->pos.y += 5;
        ft_callback(infos);
    }
    else if (key == 69)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->size.x *= 1.1f;
        infos->state->size.y *= 1.1f;
        infos->state->size.z *= 1.1f;
        /*infos->state->pos.x -= infos->state->pos.x;
        infos->state->pos.y -= infos->state->pos.y;
        infos->state->pos.z -= infos->state->pos.z;*/

        ft_callback(infos);
    }
    else if (key == 78)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->size.x /= 1.1f;
        infos->state->size.y /= 1.1f;
        infos->state->size.z /= 1.1f;
        /*infos->state->pos.x += infos->state->pos.x;
        infos->state->pos.y += infos->state->pos.y;
        infos->state->pos.z += infos->state->pos.z;*/
        ft_callback(infos);
    }
    else if (key == 91)
    {
       // mlx_clear_window(infos->mlx_ptr, infos->win_ptr);
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.x += 0.1f;
        ft_callback(infos);
    }
    // key = 5
    else if (key == 87)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.x -= 0.1f;
        ft_callback(infos);
    }
    // key = 6
        else if (key == 88)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.y += 0.1f;
        ft_callback(infos);
    }
    // key = 4
    else if (key == 86)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.y -= 0.1f;
        ft_callback(infos);
    }
    // key = 9
    else if (key == 92)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.z += 0.1f;
        ft_callback(infos);
    }
    //key = 7
    else if (key == 89)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->rota.z -= 0.1f;
        ft_callback(infos);
    }
    //key = c
    else if (key == 8)
    {
        infos->colid++;
        if (infos->colid > 5)
            infos->colid = 0;
        if (infos->colid == 0)
            infos->bcol = 0x000000;
        if (infos->colid == 1)
            infos->bcol = 0x003B3E;
        if (infos->colid == 2)
            infos->bcol = 0x0A3E00;
        if (infos->colid == 3)
            infos->bcol = 0x3C003E;
        if (infos->colid == 4)
            infos->bcol = 0x542E00;
        if (infos->colid == 5)
            infos->bcol = 0x540000;
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        ft_callback(infos);
    }
    else if (key == 121)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->pos.z += 5;
        ft_callback(infos);
    }
    else if (key == 116)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->state->pos.z -= 5;
        ft_callback(infos);
    }
    //key = p
    else if (key == 35)
    {
        ft_bcolor(infos->img, infos->bcol, (infos->height * infos->width));
        infos->boolp = !infos->boolp;
        // if (infos->boolp == 0)
        //     infos->boolp = 1;
        // else if (infos->boolp == 1)
        //     infos->boolp = 0;
        ft_callback(infos);
    }
    return (0);
}