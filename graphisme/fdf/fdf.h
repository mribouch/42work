/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:34:57 by mribouch          #+#    #+#             */
/*   Updated: 2019/02/18 17:53:52 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdlib.h>
#include <OpenGl/gl.h>
# include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct  s_point
{
    float             x;
    float             y;
    float             z;
    int             num;
}               t_point;

typedef struct  s_var
{
    float mx;
    float my;
}               t_var;

typedef struct  s_map
{
    int **map;
    int width;
    int height;
}               t_map;

typedef struct  s_window
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     width;
    int     height;
    t_point *vertices;
    t_map   *mapinf;
    t_var   *var;
}               t_window;

int         ft_dealkey(int key, t_window *infos);
t_map       *ft_read(int fd, t_window *infos, t_map *mapinf);
void        ft_draw(t_window *infos);
void        ft_line(t_window *infos, float x1, float y1, float x2, float y2);
t_point     *ft_get_point(t_point *vertices, t_map *mapinf, t_var *var);
t_window    *ft_more_z(t_window *infos);
t_window    *ft_less_z(t_window *infos);
t_window    *ft_up(t_window *infos);
t_window    *ft_down(t_window *infos);
t_window    *ft_left(t_window *infos);
t_window    *ft_right(t_window *infos);
t_window    *ft_zoom(t_window *infos);
t_window    *ft_dezoom(t_window *infos);

#endif