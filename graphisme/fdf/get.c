/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:14:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 18:46:33 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int ft_centre_x(t_point *vertices, t_map *mapinf)
{
    int i;
    int index;

    i = 0;
    while (vertices[0].x != 350)
    {
        vertices[0].x++;
        i++;
    }
    vertices[0].x = vertices[0].x - i;
    return (i);
}*/

t_point     *ft_centre_map(t_point *vertices, t_map *mapinf)
{
    int i;
    int j;

    i = 0;
    j = vertices[mapinf->width * mapinf->height - 1].y;
    ft_putstr("f3gf42g ");
    ft_putnbr(j);
    while (i <= mapinf->height * mapinf->width)
    {
        vertices[i].x = vertices[i].x + 350;
        vertices[i].y = vertices[i].y + 350 - j / 2;
        i++;
    }
    return (vertices);
}

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
        while (j < mapinf->width)
        {
            vertices[v].x = ((dx / 2));
            vertices[v].y = ((dy / 4));
            vertices[v].z = (mapinf->map[i][j]);
            vertices[v].num = num;
            j++;
            dx = dx + var->mx;
            dy = dy + var->my;
            num++;
            v++;
        }
        c++;
        dx = c * (-1 * var->my);
        j = 0;
        dy = var->my * c;
        i++;
    }
    ret = ft_centre_map(ret, mapinf);
    return (ret);
}