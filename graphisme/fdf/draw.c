/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:26:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 12:50:06 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
                ft_line(infos, infos->vertices[v].x, infos->vertices[v].y - infos->vertices[v].z,
                infos->vertices[v + 1].x, infos->vertices[v + 1].y - infos->vertices[v + 1].z);
            }
            if (i < infos->mapinf->height - 1)
                ft_line(infos, infos->vertices[v].x, infos->vertices[v].y - infos->vertices[v].z,
                    infos->vertices[v + infos->mapinf->width].x,
                        infos->vertices[v + infos->mapinf->width].y - infos->vertices[v + infos->mapinf->width].z);
            v++;
            j++;
        }
        j = 0;
        i++;
    }
}*/

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
}
