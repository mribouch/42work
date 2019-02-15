/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:19:25 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/15 16:54:34 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void    ft_print_map(t_map *mapinf)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (mapinf->map[i] != 0)
    {
        //ft_putendl("NEWLINE");
        while (j < mapinf->width)
        {
         //   ft_putstr("x = ");
           // ft_putnbr(mapinf->map[i][j]);
           // ft_putchar('\n');
            j++;
        }
        j = 0;
        i++;
    }
}

void    ft_line(t_window *infos, float x1, float y1, float x2, float y2)
{
    float dx;
    float dy;
    int i;
    int xinc;
    int yinc;
    float cumul;
    float x;
    float y;

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    i = 1;
    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = fabsf(dx);
    dy = fabsf(dy);
    mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, (int)x, (int)y, 0x00AFFF);
    if (dx > dy)
    {
        cumul = dx / 2;
        while (i++ <= dx)
        {
            x += xinc ;
            cumul += dy ;
            if (cumul >= dx)
            {
                cumul -= dx;
                y += yinc;
            }
            mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, (int)x, (int)y, 0x00AFFF);
        }
    }
    else
    {
        cumul = dy / 2;
        i = 1;
        while (i++ <= dy)
        {
            y += yinc;
            cumul += dx;
            if (cumul >= dy)
            {
                cumul -= dy;
                x += xinc;
            }
            mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, (int)x, (int)y, 0x00AFFF);
        }
    }
}

t_var   *ft_fill_var(t_var *var)
{
    var->mx = 20;
    var->my = 20;
    return (var);
}

int main(int ac, char **av)
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         fd;
    t_window    *infos;
    t_map       *mapinf;
    t_point     *vertices;
    t_var       *var;

    if (ac != 2)
        ft_putendl("usage : ./fdf file_name");
    else
    {
        if (!(mapinf = malloc(sizeof(t_map))))
            return (0);
        if (!(infos = malloc(sizeof(t_window))))
            return (0);
        fd = open(av[1], O_RDONLY);
        mlx_ptr = mlx_init();
        win_ptr = mlx_new_window(mlx_ptr, 700, 700, "testwin");
        infos->mlx_ptr = mlx_ptr;
        infos->win_ptr = win_ptr;
        mapinf = ft_read(fd, infos, mapinf);
        if (!(vertices = malloc(sizeof(t_point) * (mapinf->width * (mapinf->height)))))
            return (0);
        if (!(var = malloc(sizeof(t_var))))
            return (0);
        var = ft_fill_var(var);
        vertices = ft_get_point(vertices, mapinf, var);
        infos->vertices = vertices;
        infos->mapinf = mapinf;
        infos->var = var;
        ft_print_map(mapinf);
        ft_draw(infos);
        mlx_key_hook(win_ptr, ft_dealkey, infos);
        mlx_loop(mlx_ptr);
    }
}