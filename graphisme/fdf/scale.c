/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:48:15 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 12:52:20 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_nl(int v, t_window *infos)
{
    int i;

    i = 0;
    while (i <= infos->mapinf->height * infos->mapinf->height)
    {
        if (v == i)
            return (1);
        i = i + 3;
    }
    return (0);
}

/*t_window   *ft_zoom(t_window *infos)
{
    int i;
    int j;
    int v;
    int dx;
    int dy;

    i = -1;
    j = 0;
    v = 1;
    dx = infos->var->mx / 2;
    dy = infos->var->my / 4;
    infos->vertices[0].y = infos->vertices[0].y - dy;
    while (j < infos->mapinf->width * infos->mapinf->height - 1)
    {
        ft_putendl("-----------------------------");
        i++;
        ft_putstr("vertices v = ");
        ft_putnbr(v);
        ft_putchar('\n');
        ft_putstr("i = ");
        ft_putnbr(i);
        ft_putchar('\n');
        ft_putstr("mx = ");
        ft_putnbr(infos->var->mx);
        ft_putchar('\n');
        ft_putstr("my = ");
        ft_putnbr(infos->var->my);
        ft_putchar('\n');
        if (ft_nl(v, infos) != 1)
        {
            ft_putendl("DEBUG i < width");
            infos->vertices[v].x = infos->vertices[v - 1].x + dx * 3;
            infos->vertices[v].y = infos->vertices[v - 1].y + dy * 2;
        }
        else if (ft_nl(v, infos) == 1)
        {
            ft_putnbr(v);
            ft_putendl("DEBUG NL");
            infos->vertices[v].x = infos->vertices[v - infos->mapinf->width].x - 3 * dx;
            infos->vertices[v].y = infos->vertices[v - infos->mapinf->width].y + 2 * dy;
            i = 0;
        }
        v++;
        j++;
    }
    return (infos);
}*/

t_window   *ft_zoom(t_window *infos)
{
    int v;

    v = 0;
    while (v < infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[v].x = infos->vertices[v].x * 2;
        infos->vertices[v].y = infos->vertices[v].y * 2;
        infos->vertices[v].z = infos->vertices[v].z * 2;
        v++;
    }
    return (infos);
}

t_window   *ft_dezoom(t_window *infos)
{
    int v;

    v = 0;
    while (v <= infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[v].x = infos->vertices[v].x / 2;
        infos->vertices[v].y = infos->vertices[v].y / 2;
        infos->vertices[v].z = infos->vertices[v].z / 2;
        v++;
    }
    return (infos);
}