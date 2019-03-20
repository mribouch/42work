/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:12:42 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/20 19:05:07 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#include <stdio.h>

t_point    *ft_isov(t_window *infos)
{
    int     i;

    float   x;
    float   y;
    float   z;

    x = 0;
    y = 0;
    z = 0;
    float   rot[4][4] = {{cos(0.785398) , -sin(0.785398), 0, 0},
                    {sin(0.785398), cos(0.785398), 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};
    float   rot2[4][4] = {{1 , 0, 0, 0},
                    {0, cos(0.523599), -sin(0.523599), 0},
                    {0, sin(0.523599), cos(0.523599), 0},
                    {0, 0, 0, 1}};
    i = 0;
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    i = 0;
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot2[0][0] * infos->iso[i].x + rot2[0][1] * infos->iso[i].y + rot2[0][2] * infos->iso[i].z + rot2[0][3] * 1;
        y = rot2[1][0] * infos->iso[i].x + rot2[1][1] * infos->iso[i].y + rot2[1][2] * infos->iso[i].z + rot2[1][3] * 1;
        z = rot2[2][0] * infos->iso[i].x + rot2[2][1] * infos->iso[i].y + rot2[2][2] * infos->iso[i].z + rot2[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

t_point *ft_persp(t_window *infos, float nb)
{
    int i;
    //int x;
    //int y;
    //int z;
    //int j;
    //float   perp[4][4] = {{1, 0, 0, 0},

    i = 0;
    while (i < infos->mapinf->width * infos->mapinf->height)
    {
        /*ft_putendl("AVANT");
        ft_putstr("i = ");
        ft_putnbr(i);
        ft_putchar('\n');
        ft_putstr("i = ");
        ft_putnbr(i);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].x = ");
        printf("%f\n", infos->iso[i].x);
        ft_putstr("infos->iso[i].y = ");
        printf("%f\n", infos->iso[i].y);
        ft_putstr("infos->iso[i].z = ");
        printf("%f\n", infos->iso[i].z);*/
        /*j = 1 / (2 - infos->iso[i].z);
        x = j * infos->iso[i].x + perp[0][1] * infos->iso[i].y + perp[0][2] * infos->iso[i].z + perp[0][3] * 1;
        y = perp[1][0] * infos->iso[i].x + j * infos->iso[i].y + perp[1][2] * infos->iso[i].z + perp[1][3] * 1;
        z = perp[2][0] * infos->iso[i].x + perp[2][1] * infos->iso[i].y + j * infos->iso[i].z + perp[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;*/
        if (infos->iso[i].z != 0)
       {
            // infos->iso[i].x = infos->iso[i].x / (1 - ((infos->iso[i].z / nb)));
            // infos->iso[i].y = infos->iso[i].y / (1 - ((infos->iso[i].z / nb)));
            (void)nb;
            infos->iso[i].x /= fabsf(infos->iso[i].z) / 500.0f;
            infos->iso[i].y /= fabsf(infos->iso[i].z) / 500.0f;
       }
        /*ft_putendl("APRES");
        ft_putstr("i = ");
        ft_putnbr(i);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].x = ");
        printf("%f\n", infos->iso[i].x);
        ft_putstr("infos->iso[i].y = ");
        printf("%f\n", infos->iso[i].y);
        ft_putstr("infos->iso[i].z = ");
        printf("%f\n", infos->iso[i].z);*/
        //infos->iso[i].x = infos->iso[i].x / (infos->iso[i].z / nb);
        //ft_putstr("infini ?");
        i++;
    }
    return (infos->iso);
}

void    ft_callback(t_window *infos)
{
    int i;

    i = 0;
    while (i < infos->mapinf->width * infos->mapinf->height)
    {
        infos->iso[i].x = infos->vertices[i].x * infos->state->size.x;
        infos->iso[i].y = infos->vertices[i].y * infos->state->size.y;
        infos->iso[i].z = infos->vertices[i].z * infos->state->size.z;
        i++;
    }
    infos->iso = ft_rotx(infos);
    infos->iso = ft_roty(infos);
    infos->iso = ft_rotz(infos);
    i = 0;
    //infos->iso = ft_isov(infos);
    while (i < infos->mapinf->width * infos->mapinf->height)
    {
        infos->iso[i].x = infos->iso[i].x + infos->state->pos.x;
        infos->iso[i].y = infos->iso[i].y + infos->state->pos.y;
        infos->iso[i].z = infos->iso[i].z + infos->state->pos.z;
        i++;
    }
    infos->iso = ft_persp(infos, 450.0f);
    ft_draw_iso(infos);
    mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
}

        /*ft_putendl("APRES :");
        ft_putstr("infos->state->pos.x = ");
        ft_putnbr(infos->state->pos.x);
        ft_putchar('\n');
        ft_putstr("infos->vertices[i].x = ");
        ft_putnbr(infos->vertices[i].x);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].x = ");
        ft_putnbr(infos->iso[i].x);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].y = ");
        ft_putnbr(infos->iso[i].y);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].z = ");
        ft_putnbr(infos->iso[i].z);
        ft_putchar('\n');*/