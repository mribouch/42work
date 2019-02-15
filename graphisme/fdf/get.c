/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:14:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 12:52:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point    *ft_get_point(t_point *vertices, t_map *mapinf, t_var *var)
{
    int i;
    int j;
    int dx;
    int dy;
    int c;
    int num;
    int v;
    t_point *ret;

    i = 0;
    j = 0;
    dx = 0;
    dy = 0;
    c = 0;
    num = 1;
    v = 0;
    ret = vertices;

    while (mapinf->map[i] != 0)
    {
        //ft_putendl("DEBUG FIRST BOUCLE");
        while (j < mapinf->width)
        {
            //ft_putendl("DEBUG SEC BOUCLE");
            //ft_line(infos, (xi + d + (dx / 2)), (yi + (dy / 4)), (xi + dx + (d / 2) + d), (yi + (d / 2) + d));
            vertices[v].x = ((dx / 2));
            vertices[v].y = ((dy / 4));
            vertices[v].z = (mapinf->map[i][j]);
            vertices[v].num = num;
            //mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, (xi + d + (dx / 2)), (yi + (dy / 4)), 0x00AFFF);
            j++;
            dx = dx + var->mx;
            dy = dy + var->my;
            //dx = dx + 30;
            //dy = dy + 45;
            num++;
            v++;
        }
        c++;
        dx = c * (-1 * var->my);
        //dx = c * (-45);
        j = 0;
        dy = var->my * c;
        //dy = 45 * c;
        i++;
    }
    return (ret);
}

/*t_point    *ft_get_point(t_point *vertices, t_map *mapinf, t_var *var)
{
    int i;
    int j;
    int xi;
    int yi;
    int dx;
    int dy;
    int d;
    int c;
    int num;
    int v;
    t_point *ret;

    i = 0;
    j = 0;
    xi = 180;
    yi = 100;
    d = 30;
    dx = 0;
    dy = 0;
    c = 0;
    num = 1;
    v = 0;
    ret = vertices;

    while (mapinf->map[i] != 0)
    {
        //ft_putendl("DEBUG FIRST BOUCLE");
        while (j < mapinf->width)
        {
            //ft_putendl("DEBUG SEC BOUCLE");
            //ft_line(infos, (xi + d + (dx / 2)), (yi + (dy / 4)), (xi + dx + (d / 2) + d), (yi + (d / 2) + d));
            vertices[v].x = (xi + d + (dx / 2));
            vertices[v].y = (yi + (dy / 4));
            vertices[v].z = (mapinf->map[i][j]);
            vertices[v].num = num;
            //mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, (xi + d + (dx / 2)), (yi + (dy / 4)), 0x00AFFF);
            j++;
            dx = dx + var->mx;
            dy = dy + var->my;
            //dx = dx + 30;
            //dy = dy + 45;
            num++;
            v++;
        }
        c++;
        dx = c * (-1 * var->my);
        //dx = c * (-45);
        j = 0;
        dy = var->my * c;
        //dy = 45 * c;
        i++;
    }
    return (ret);
}*/