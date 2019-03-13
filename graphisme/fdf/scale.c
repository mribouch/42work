/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:48:15 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/12 17:06:23 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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

/*t_window   *ft_zoom(t_window *infos)
{
    ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    infos->state->size.x += 1;
    infos->state->size.y += 1;
    infos->state->size.z += 1;
    return (infos);
}

t_window   *ft_dezoom(t_window *infos)
{
    /*int v;
    int i;
    //int test;

    v = 0;
    i = 0;
    ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (v < infos->mapinf->width * infos->mapinf->height)
    {
        infos->iso[v].x = infos->vertices[v].x / 1.1;
        infos->iso[v].y = infos->vertices[v].y / 1.1;
        infos->iso[v].z = infos->vertices[v].z / 1.1;
        v++;
    }
    ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    infos->state->size.x -= 1;
    infos->state->size.y -= 1;
    infos->state->size.z -= 1;
    return (infos);
}*/