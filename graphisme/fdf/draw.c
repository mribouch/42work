/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:26:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/18 17:53:50 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_over(t_window *infos, int v)
{
    if (infos->vertices[v].x >= infos->width || infos->vertices[v].x <= 0)
        return (1);
    if (infos->vertices[v].y >= infos->height || infos->vertices[v].y <= 0)
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
            {
                ft_line(infos, infos->vertices[v].x, infos->vertices[v].y - infos->vertices[v].z,
                infos->vertices[v + 1].x, infos->vertices[v + 1].y - infos->vertices[v + 1].z);
            }
            if (i < infos->mapinf->height - 1 && ft_over(infos, v) == 0)
            {
                ft_line(infos, infos->vertices[v].x, infos->vertices[v].y - infos->vertices[v].z,
                    infos->vertices[v + infos->mapinf->width].x,
                        infos->vertices[v + infos->mapinf->width].y - infos->vertices[v + infos->mapinf->width].z);
            }
            v++;
            j++;
        }
        j = 0;
        i++;
    }
}

/*void    ft_draw(t_window *infos)
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
            if (j < infos->mapinf->width - 1)
            {
                ft_line(infos, infos->vertices[v].x + 210, infos->vertices[v].y - infos->vertices[v].z + 100,
                infos->vertices[v + 1].x + 210, infos->vertices[v + 1].y - infos->vertices[v + 1].z + 100);
            }
            if (i < infos->mapinf->height - 1)
                ft_line(infos, infos->vertices[v].x + 210, infos->vertices[v].y - infos->vertices[v].z + 100,
                    infos->vertices[v + infos->mapinf->width].x + 210,
                        infos->vertices[v + infos->mapinf->width].y - infos->vertices[v + infos->mapinf->width].z + 100);
            v++;
            j++;
        }
        j = 0;
        i++;
    }
}*/
