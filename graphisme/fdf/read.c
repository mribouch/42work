/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:32:07 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 14:08:24 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         ft_get_num(char *full, int k)
{
    char    *res;
    int     i;
    int     ret;

    i = 0;
    while (full[k] < '0' || full[k] > '9')
        k++;
    while (full[k] >= '0' && full[k] <= '9')
    {
        i++;
        k++;
    }
    k = k - i;
    if (!(res = malloc(sizeof(char) * (i + 1))))
        return (0);
    i = 0;
    while ((full[k] >= '0' && full[k] <= '9') && full[k] != '\n')
    {
        res[i] = full[k];
        k++;
        i++;
    }
    res[i] = '\0';
    ret = ft_atoi(res);
    free(res);
    return (ret);
}

#include <stdio.h>

int     **ft_fill_map(int **map, char *full)
{
    int     i;
    int     k;
    int     nbl;

    i = 0;
    k = 0;
    nbl = 0;
    while (full[k] != '\0')
    {
        if (full[k] == '\n')
        {
            nbl++;
            i = 0;
        }
        else if (full[k] >= '0' && full[k] <= '9')
        {
            ft_putstr("k = ");
            ft_putnbr(k);
            ft_putchar('\n');
            map[nbl][i] = ft_get_num(full, k);
            if (full[k] >= '0' && full[k] <= '9')
            {
                while (full[k] >= '0' && full[k] <= '9')
                    k++;
                k = k - 1;
            }
            i++;
        }
        k++;
    }
    map[nbl] = 0;
    return (map);
}

static int      ft_rd_nbc(char *full)
{
    int i;
    int nbc;

    i = 0;
    nbc = 0;
    while (full[i] != '\n')
    {
        if (full[i] >= '0' && full[i] <= '9')
        {
            while (full[i] >= '0' && full[i] <= '9')
                i++;
            nbc++;
        }
        else
            i++;
    }
    return (nbc);
}

static int      ft_rd_nbl(char *full)
{
    int i;
    int nbl;

    i = 0;
    nbl = 0;
    while (full[i] != '\0')
    {
        if (full[i] == '\n')
            nbl++;
        i++;
    }
    return (nbl);
}

t_map   *ft_read(int fd, t_window *infos, t_map *mapinf)
{
    char    *line;
    int     i;
    int     nbl;
    int     nbc;
    char    *full;

    i = 0;
    nbl = 0;
    nbc = 0;
    full = ft_strnew(1);
    (void)infos;
    while (get_next_line(fd, &line) > 0)
    {
        full = ft_strjoin(full, line);
        full = ft_strjoin(full, "\n");
    }
    ft_putendl(full);
    nbl = ft_rd_nbl(full);
    nbc = ft_rd_nbc(full);
    mapinf->height = nbl;
    mapinf->width = nbc;
    //ft_putendl("TEST");
    if (!(mapinf->map = malloc(sizeof(int*) * (nbl + 1))))
        return (0);
    while (nbl > 0)
    {
        if (!(mapinf->map[i] = malloc(sizeof(int) * (nbc + 1))))
            return (0);
        nbl--;
        i++;
    }
    mapinf->map = ft_fill_map(mapinf->map, full);
    return (mapinf);
}