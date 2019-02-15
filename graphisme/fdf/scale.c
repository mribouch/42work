/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:48:15 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 19:34:14 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int ft_nl(int v, t_window *infos)
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
}*/

t_window   *ft_zoom(t_window *infos)
{
    int v;
    int i;
    int test;

    v = 0;
    i = 0;
    while (v < infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[v].x = infos->vertices[v].x * 2;
        infos->vertices[v].y = infos->vertices[v].y * 2;
        infos->vertices[v].z = infos->vertices[v].z * 2;
        v++;
    }
    test = infos->vertices[0].x / 2;
    while (i < infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[i].x = infos->vertices[i].x - test;
        infos->vertices[i].y = infos->vertices[i].y - test;
        i++;
    }
    return (infos);
}

t_window   *ft_dezoom(t_window *infos)
{
    int v;
    int i;
    int test;

    v = 0;
    i = 0;
    while (v < infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[v].x = infos->vertices[v].x / 2;
        infos->vertices[v].y = infos->vertices[v].y / 2;
        infos->vertices[v].z = infos->vertices[v].z / 2;
        v++;
    }
    test = infos->vertices[0].x * 2;
    while (i < infos->mapinf->width * infos->mapinf->height)
    {
        infos->vertices[i].x = infos->vertices[i].x + test / 2;
        infos->vertices[i].y = infos->vertices[i].y + test / 2;
        i++;
    }
    return (infos);
}