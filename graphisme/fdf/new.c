/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:26:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/20 18:56:15 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


int     *ft_fill_pixel_new(t_window *infos, int x, int y, int color1, int color2, int j, float nbp)
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

void    ft_line_new(t_window *infos, t_point vertices1, t_point vertices2)
{
    float dx;
    float dy;
    int i;
    int xinc;
    int yinc;
    float cumul;
    float x;
    float y;
    /*ft_putstr("x = ");
    ft_putnbr(vertices2.x);
    ft_putchar('\n');
    ft_putstr("y = ");
    ft_putnbr(vertices2.y);
    ft_putchar('\n');
    ft_putstr("z = ");
    ft_putnbr(vertices2.z);
    ft_putchar('\n');*/
    x = vertices1.x + infos->width / 2;
    y = vertices1.y + infos->height / 2;
    dx = vertices2.x - vertices1.x;
    dy = vertices2.y - vertices1.y;
    //GALAXY LIKE
    /*vertices1.x = vertices1.x * (dx / (vertices1.z / 500.0f));
    vertices1.y = vertices1.y * (dy / (vertices1.z / 500.0f));
    vertices2.x = vertices2.x * (dx / (vertices2.z / 500.0f));
    vertices2.y = vertices2.y * (dy / (vertices2.z / 500.0f));*/
    i = 1;
    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = fabsf(dx);
    dy = fabsf(dy);
    infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
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
            infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dx);
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
            infos->img = ft_fill_pixel_new(infos, (int)x, (int)y, vertices1.color, vertices2.color, i, dy);
        }
    }
}

int     ft_over_new(t_window *infos, int v)
{
    if (infos->iso[v].z <= 1.0f)
        return (1);
    /*if (infos->vertices[v].y > infos->height || infos->vertices[v].y < 0)
        return (1);*/
    return (0);
}

#include <stdio.h>




void    ft_draw_iso(t_window *infos)
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
            //     ft_putendl("SUIVANT");
            //     ft_putstr("infos->iso[i].x = ");
            //     printf("%f\n", infos->iso[i].x);
            //     ft_putstr("infos->iso[i].y = ");
            //     printf("%f\n", infos->iso[i].y);
            //     ft_putstr("infos->iso[i].z = ");
            //     printf("%f\n", infos->iso[i].z);
            // ft_putendl("TEST ICI");
            //if (infos->iso[i].z >= 0)
           // {
                if (j < infos->mapinf->width - 1 && ft_over_new(infos, v) == 0)
                    ft_line_new(infos, infos->iso[v], infos->iso[v + 1]);
                if (i < infos->mapinf->height - 1 && ft_over_new(infos, v) == 0)
                    ft_line_new(infos, infos->iso[v], infos->iso[v + infos->mapinf->width]);
           // }
            v++;
            j++;
        }
        //ft_putendl("ISO 2");
        j = 0;
        i++;
    }
}




void    ft_draw_new(t_window *infos)
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
            if (j < infos->mapinf->width - 1 /*&& ft_over_new(infos, v) == 0*/)
                ft_line_new(infos, infos->vertices[v], infos->vertices[v + 1]);
            if (i < infos->mapinf->height - 1 /*&& ft_over_new(infos, v) == 0*/)
                ft_line_new(infos, infos->vertices[v], infos->vertices[v + infos->mapinf->width]);
            v++;
            j++;
        }
        j = 0;
        i++;
    }
}

t_point    *ft_new(t_window *infos, t_point *vertices, char **col)
{
    int i;
    int j;
    int dx;
    int dy;
    int c;
    int num;
    int v;

    i = 0;
    j = 0;
    dx = 0;
    dy = 0;
    c = 0;
    num = 1;
    v = 0;
    //ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));

    while (infos->mapinf->map[i] != 0)
    {
        while (j < infos->mapinf->width)
        {
            vertices[v].x = dx - infos->mapinf->width * 10;
            vertices[v].y = dy - infos->mapinf->height * 10;
            vertices[v].z = (infos->mapinf->map[i][j]);
            vertices[v].num = num;
            vertices[v].color = ft_hex2int(col[v]);
            j++;
            dx = dx + 20;
            num++;
            v++;
        }
        c++;
        dx = 0;
        j = 0;
        dy = 20 * c;
        i++;
    }
   // infos->vertices = ft_centre_map_new(infos->vertices, infos->mapinf, infos);
    //ft_draw_new(infos);
    return (vertices);
    //mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img_ptr, 0, 0);
}