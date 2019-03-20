/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:34:57 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/20 18:43:59 by mribouch         ###   ########.fr       */
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
    int             color;
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

typedef struct  s_color
{
    int r;
    int g;
    int b;
}               t_color;

typedef struct  s_mod
{
    float   x;
    float   y;
    float   z;
}               t_mod;

typedef struct  s_state
{
    t_mod   size;
    t_mod   rota;
    t_mod   pos;
}               t_state;


typedef struct  s_window
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     width;
    int     height;
    int     *img;
    int     colid;
    int     bcol;
    int     boolp;
    t_point *vertices;
    t_point *iso;
    t_map   *mapinf;
    t_var   *var;
    t_state *state;
}               t_window;

int         ft_dealkey(int key, t_window *infos);
t_map       *ft_read(int fd, t_map *mapinf, char ***col);
void        ft_draw(t_window *infos);
int         ft_lerp(int i, int color1, int color2, float nbp);
void        ft_line(t_window *infos, t_point vertices1, t_point vertices2);
int         ft_get_c(char *full);
int         ft_get_s(char *full);
int         *ft_get_img_point(t_window *infos);
int	        ft_hex2int(char *hex);
char		**ft_strsplit_fdf(char *str);
//t_point     *ft_get_point(t_point *vertices, t_map *mapinf, t_var *var, char **col, t_window *infos);
t_point     *ft_new(t_window *infos, t_point *vertices, char **col);
t_window    *ft_dezoom(t_window *infos);
t_point     *ft_get_caval(t_point *vertices, t_map *mapinf, t_var *var, t_window *infos);
t_point     *ft_rotx(t_window *infos);
t_point     *ft_roty(t_window *infos);
t_point     *ft_rotz(t_window *infos);
//void        ft_new(t_window *infos);
void        ft_draw_new(t_window *infos);
void        ft_draw_iso(t_window *infos);
//void        ft_draw_persp(t_window *infos);
t_point     *ft_iso(t_window *infos);
t_point     *ft_isov(t_window *infos);
void        ft_callback(t_window *infos);
void	    ft_bblue(void *s, size_t n);
void	    ft_bcolor(void *s, int color, size_t n);


#endif