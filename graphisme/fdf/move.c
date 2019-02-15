/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:11:33 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 13:21:30 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void    ft_print_list(t_point *lstp)
{
    while(lstp != 0)
    {
        ft_putendl("--NEW POINT--");
        ft_putchar('\n');
        ft_putstr("x = ");
        ft_putnbr(lstp->x);
        ft_putchar('\n');
        ft_putstr("y = ");
        ft_putnbr(lstp->y);
        ft_putchar('\n');
        ft_putstr("z = ");
        ft_putnbr(lstp->z);
        ft_putchar('\n');
        lstp = lstp->next;
    }
}*/

t_window    *ft_more_z(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        if (infos->vertices[i].z == -1)
            infos->vertices[i].z = infos->vertices[i].z + 2;
        else if (infos->vertices[i].z != 0)
            infos->vertices[i].z = infos->vertices[i].z + 1;
        i++;
    }
    return (infos);
}

t_window    *ft_less_z(t_window *infos)
{
    int i;

    i = 0;
    while (i < (infos->mapinf->width * infos->mapinf->height))
    {
        if (infos->vertices[i].z == 1)
            infos->vertices[i].z = infos->vertices[i].z - 2;
        else if (infos->vertices[i].z != 0)
            infos->vertices[i].z = infos->vertices[i].z - 1;
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
        infos->vertices[i].y = infos->vertices[i].y - 1;
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
        infos->vertices[i].y = infos->vertices[i].y + 1;
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
        infos->vertices[i].x = infos->vertices[i].x + 1;
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
        infos->vertices[i].x = infos->vertices[i].x - 1;
        i++;
    }
    return (infos);
}