/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:19:25 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/21 18:15:30 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

t_var   *ft_fill_var(t_var *var)
{
    var->mx = 30;
    var->my = 30;
    return (var);
}

int    *ft_get_img(int *img, void *img_ptr, t_window *infos)
{
    int bpp;
    int s_l;
    int endian;

    img = (int*)mlx_get_data_addr(img_ptr, &bpp, &s_l, &endian);
    ft_putendl("CECI EST L'IMAGE : ");
    ft_bzero(img, infos->width * infos->height);
    return (img);
}

t_state *ft_fill_state(t_state *state)
{
    state->size.x = 1;
    state->size.y = 1;
    state->size.z = 1;
    state->rota.x = 0;
    state->rota.y = 0;
    state->rota.z = 0;
    state->pos.x = 0;
    state->pos.y = 0;
    state->pos.z = 0;
    return (state);
}

void    ft_putmenu(t_window *infos)
{
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 10, 0x5995DA, "Move right     : Right arrow");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 30, 0x5995DA, "Move left      : Left arrow");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 50, 0x5995DA, "Move up        : Up arrow");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 70, 0x5995DA, "Move down      : Down arrow");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 90, 0x5995DA, "Move frontward : Page up (Perspective view)");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 110, 0x5995DA, "Move Backward  : Page down (Perspective view)");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1300, 10, 0x5995DA, "Zoom In  : numpad +");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1300, 30, 0x5995DA, "Zoom Out : numpad -");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 940, 0x5995DA, "Change Background Color : c");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 10, 960, 0x5995DA, "Perspective view        : p");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 860, 0x5995DA, "Rotate X up    : Numpad 8");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 880, 0x5995DA, "Rotate X down  : Numpad 5");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 900, 0x5995DA, "Rotate Y right : Numpad 6");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 920, 0x5995DA, "Rotate Y left  : Numpad 4");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 940, 0x5995DA, "Rotate Z left  : Numpad 7");
    mlx_string_put(infos->mlx_ptr, infos->win_ptr, 1220, 960, 0x5995DA, "Rotate Z right : Numpad 9");
}

int main(int ac, char **av)
{
    void        *mlx_ptr;
    void        *win_ptr;
    void        *img_ptr;
    int         fd;
    char        **col;
    int         *img;
    //int         test;
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
        if (fd < 0)
        {
            ft_putendl("File does not exist.");
            return (0);
        }
        mlx_ptr = mlx_init();
        infos->height = 1000;
        infos->width = 1500;
        win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "testwin");
        infos->mlx_ptr = mlx_ptr;
        infos->win_ptr = win_ptr;
        img = NULL;
        img_ptr = mlx_new_image(infos->mlx_ptr, 1500, 1000);
        infos->img_ptr = img_ptr;
        img = ft_get_img(img, img_ptr, infos);
        if ((mapinf = ft_read(fd, mapinf, &col)) == 0)
        {
            ft_putendl("Not valid file.");
            exit(0);
        }
        if (!(vertices = malloc(sizeof(t_point) * (mapinf->width * (mapinf->height)) + 1)))
            return (0);
        if (!(var = malloc(sizeof(t_var))))
            return (0);
        if (!(infos->iso = malloc(sizeof(t_point) * (mapinf->width * (mapinf->height)) + 1)))
            return (0);
        if (!(infos->state = malloc(sizeof(t_state))))
            return (0);
        ft_putendl("Apres malloc vertices dans main ?");
        var = ft_fill_var(var);
        infos->state = ft_fill_state(infos->state);
        ft_putendl("JUSTD LS");
        infos->boolp = 0;
        infos->bcol = 0x000000;
        infos->colid = 0;
        infos->img = img;
        infos->var = var;
        infos->mapinf = mapinf;
        vertices = ft_new(infos, vertices, col);
        infos->vertices = vertices;
        infos->iso = ft_new(infos, infos->iso, col);
        ft_putendl("CIICI");
        //infos->iso = iso;
        //infos->iso = ft_isov(infos);
        //ft_draw_iso(infos);
        ft_putendl("gngrn");
        ft_callback(infos);
        ft_putmenu(infos);
        //ft_putendl("CIICI");
        //mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, img_ptr, 0, 0);
        mlx_key_hook(win_ptr, ft_dealkey, infos);
        mlx_loop(mlx_ptr);
    }
}