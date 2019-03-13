/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:26:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/13 18:32:49 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int     *ft_fill_pixel(t_window *infos, int x, int y, int color1, int color2, int j, float nbp)
{
    int i;

    (void)color2;
    i = x + y * infos->width;
    if (x >= infos->width || y >= infos->height || x < 0 || y < 0)
        ;
    else
        infos->img[i] = ft_lerp(j, color1, color2, nbp);
        //infos->img[i] = 0xFFFFFF;
    return (infos->img);
}

void    ft_line(t_window *infos, t_point vertices1, t_point vertices2)
{
    float dx;
    float dy;
    int i;
    int xinc;
    int yinc;
    float cumul;
    float x;
    float y;

    x = vertices1.x;
    y = vertices1.y - vertices1.z;
    dx = vertices2.x - vertices1.x;
    dy = (vertices2.y - vertices2.z) - (vertices1.y - vertices1.z);
    i = 1;
    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = fabsf(dx);
    dy = fabsf(dy);
    infos->img = ft_fill_pixel(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
    if (dx > dy)
    {
        cumul = dx / 2;
        while (i++ <= dx)
        {
            x += xinc ;
            cumul += dy ;
            if (cumul >= dx)
            {
                cumul -= dx;
                y += yinc;
            }
            infos->img = ft_fill_pixel(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
        }
    }
    else
    {
        cumul = dy / 2;
        i = 1;
        while (i++ <= dy)
        {
            y += yinc;
            cumul += dx;
            if (cumul >= dy)
            {
                cumul -= dy;
                x += xinc;
            }
            infos->img = ft_fill_pixel(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dy);
        }
    }
}

int     ft_over(t_window *infos, int v)
{
    if (infos->vertices[v].x > infos->width || infos->vertices[v].x < 0)
        return (1);
    if (infos->vertices[v].y > infos->height || infos->vertices[v].y < 0)
        return (1);
    return (0);
}

void    ft_draw(t_window *infos)
{
    int     i;
    int     j;
    int     v;

    i = 0;
    j = 0;
    v = 0;
    while (i < infos->mapinf->height)
    {
        while (j < infos->mapinf->width)
        {
            if (j < infos->mapinf->width - 1 && ft_over(infos, v) == 0)
                ft_line(infos, infos->vertices[v], infos->vertices[v + 1]);
            if (i < infos->mapinf->height - 1 && ft_over(infos, v) == 0)
                ft_line(infos, infos->vertices[v], infos->vertices[v + infos->mapinf->width]);
            v++;
            j++;
        }
        j = 0;
        i++;
    }
}