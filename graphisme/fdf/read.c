/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:32:07 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/06 16:25:25 by mribouch         ###   ########.fr       */
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
    return (ret);
}

#include <stdio.h>

int     **ft_fill_map(t_map *mapinf, char *full)
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
            mapinf->map[nbl][i] = ft_get_num(full, k);
            if (full[k] >= '0' && full[k] <= '9')
            {
                while (full[k] != ' ' && full[k] != '\n')
                    k++;
                k = k - 1;
            }
            i++;
        }
        k++;
    }
    mapinf->map[nbl] = 0;
    return (mapinf->map);
}

static int      ft_rd_nbc(char *full)
{
    int i;
    int nbc;
    int len;

    i = 0;
    nbc = 0;
    len = ft_strlen(full);
    while (full[i] == ' ')
        i++;
    while (full[i] != '\n' && full[i] != '\0')
    {
        if (full[i] == ' ')
        {
            /*ft_putstr("i = ");
            ft_putnbr(i);
            ft_putchar('\n');*/
            while(full[i] == ' ')
                i++;
            //ft_putstr("nbc++ = ");
            nbc++;
            //ft_putnbr(nbc);
            //ft_putchar('\n');
        }
        i++;
    }
    if (full[len - 1] == ' ')
        return (-1);
    return (nbc + 1);
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

char    **ft_get_col(char **allpoint, char **col)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (allpoint[i] != 0)
        i++;
    if (!(col = malloc(sizeof(char*) * (i + 1))))
        return (0);
    i = 0;
    while (allpoint[i] != 0)
    {
        if (ft_get_c(allpoint[i]) == 0)
        {
            if (!(col[i] = malloc(sizeof(char) * 9)))
                return (0);
            col[i] = "0xFFFFFF";
        }
        else
            col[i] = ft_strsub(allpoint[i], ft_get_c(allpoint[i]), ft_strlen(allpoint[i]) - ft_get_c(allpoint[i]));
        i++;
    }
    return (col);
}

t_map   *ft_read(int fd, t_map *mapinf, char ***col)
{
    char    *line;
    int     i;
    int     nbl;
    int     nbc;
    char    *full;
    char    **allpoint;
    int     x;

    i = 0;
    nbl = 0;
    nbc = 0;
    x = 0;
    full = ft_strnew(1);
    get_next_line(fd, &line);
    full = ft_strjoin(full, line);
    full = ft_strjoin(full, "\n");
    x = ft_rd_nbc(line);
    while (get_next_line(fd, &line) > 0)
    {
        if (ft_rd_nbc(line) == -1 || x != ft_rd_nbc(line))
            return (0);
        //ft_putstr("nbc = ");
        //ft_putnbr(ft_rd_nbc(line));
        //ft_putchar('\n');
        full = ft_strjoin(full, line);
        full = ft_strjoin(full, "\n");
    }
    nbl = ft_rd_nbl(full);
    nbc = ft_rd_nbc(full);
    ft_putendl("Dans READ ?");
    mapinf->height = nbl;
    mapinf->width = nbc;
    allpoint = ft_strsplit_fdf(full);
    if (!(mapinf->map = malloc(sizeof(int*) * (nbl + 1))))
        return (0);
    while (nbl > 0)
    {
        if (!(mapinf->map[i] = malloc(sizeof(int) * (nbc + 1))))
            return (0);
        nbl--;
        i++;
    }
    *col = ft_get_col(allpoint, *col);
    mapinf->map = ft_fill_map(mapinf, full);
    return (mapinf);
}