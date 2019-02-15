/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:11:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 17:01:11 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_min_z(t_window *infos)
{
    int i;
    int j;
    int min;

    i = 0;
    j = 0;
    min = 2147483647;
    while (i < infos->mapinf->height)
    {
        while (j < infos->mapinf->width)
        {
            if (min > infos->mapinf->map[i][j])
                min = infos->mapinf->map[i][j];
            j++;
        }
        i++;
    }
    ft_putchar('\n');
    ft_putstr("min = ");
    ft_putnbr(min);
    return (min);
}

t_window    *ft_more_z(t_window *infos)
{
    int i;
    int min;

    min = ft_min_z(infos);
    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
       if (infos->vertices[i].z != min)
            infos->vertices[i].z = infos->vertices[i].z * 1.5;
        i++;
    }
    return (infos);
}

t_window    *ft_less_z(t_window *infos)
{
    int i;
    int min;

    i = 0;
    min = ft_min_z(infos);
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        if (infos->vertices[i].z != min)
            infos->vertices[i].z = infos->vertices[i].z / 1.5;
        i++;
    }
    return (infos);
}

t_window    *ft_up(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        infos->vertices[i].y = infos->vertices[i].y - 5;
        i++;
    }
    return (infos);
}

t_window    *ft_down(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        infos->vertices[i].y = infos->vertices[i].y + 5;
        i++;
    }
    return (infos);
}

t_window    *ft_right(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        infos->vertices[i].x = infos->vertices[i].x + 5;
        i++;
    }
    return (infos);
}

t_window    *ft_left(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        infos->vertices[i].x = infos->vertices[i].x - 5;
        i++;
    }
    return (infos);
}