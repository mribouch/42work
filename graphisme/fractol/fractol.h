/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:31:13 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 13:09:40 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_hsv
{
	double			h;
	double			s;
	double			v;
}				t_hsv;

typedef struct	s_value
{
	double		zmx1;
	double		zmx2;
	double		zmy1;
	double		zmy2;
	double		x1;
	double		y1;
	double		zoom;
	double		mvx;
	double		mvy;
	double		z;
	double		dx;
	double		dy;
	double		lx;
	double		ly;
	int			max_iter;
	int			lock;
	int			mult;
	int			degre;
	int			cid;
	int			lastx;
	int			lasty;
	double		lastcr;
	double		lastci;
	t_hsv		colorh;
	int			h;
}				t_value;

typedef struct	s_fract
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
}				t_fract;

typedef struct	s_cursor
{
	double		x;
	double		y;
}				t_cursor;

typedef struct	s_circle
{
	int x;
	int y;
	int d;
	int	r;
}				t_circle;

typedef struct	s_point
{
	int	x;
	int	y;
	int	color;
}				t_point;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	int			*img;
	int			fid;
	int			btnp;
	t_cursor	cursor;
	t_value		value;
	t_fract		point;
}				t_window;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_mapjs
{
	double		value;
	double		minv;
	double		maxv;
	double		mint;
	double		maxt;
}				t_mapjs;

typedef struct	s_part
{
	double		i;
	double		r;
}				t_part;

int				ft_lfract(t_window *infos);
int				ft_mandel(t_window *infos);
int				ft_julia(t_window *infos);
int				ft_bship(t_window *infos);
int				ft_dealkey(int key, t_window *infos);
int				ft_dealmouse(int button, int x, int y, t_window *infos);
int				ft_get_cursor(int x, int y, t_window *infos);
int				ft_check_button(int button, int x, int y, t_window *infos);
void			ft_change_stat(t_window *infos, int key);
void			ft_move_julia(t_window *infos, int key);
void			ft_change_id(t_window *infos, int key);
t_window		*ft_init(t_window *infos);
t_window		*ft_init_bship(t_window *infos);
t_window		*ft_init_julia(t_window *infos);
t_window		*ft_init_mandel(t_window *infos);
t_window		*ft_zoom_mandel(t_window *infos, int x, int y);
t_window		*ft_dezoom_mandel(t_window *infos, int x, int y);
t_window		*ft_color(t_window *infos);
double			ft_map(t_mapjs map);
double			ft_map2(t_mapjs map);
void			ft_fullcircle(t_window *infos, t_point c
					, int r, int color);
void			ft_circle(t_window *infos, t_point c, int r, int color);
t_window		*ft_putmenu(t_window *infos);
t_window		*ft_put_slide_hsv(t_window *infos, int x, int y);
t_window		*ft_fill_imgcolor(t_window *infos, int i, double x, double y);
int				ft_create_rgb(double r, double g, double b);
int				ft_hsv2rgb(t_hsv hsv);

#endif
