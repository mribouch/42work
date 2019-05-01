/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:31:13 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:32 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"


typedef struct	s_value
{
	double		zmx1;
	double		zmx2;
	double		zmy1;
	double		zmy2;
	double		zoom;
	double		mvx;
	double		mvy;
	double		z;
	double		dx;
	double		dy;
	double		lx;
	double		ly;
	int			max_iter;
	int			mult;
	int			degre;
	int			c;
}				t_value;

typedef struct	s_fract
{
	// double		minx;
	// double		maxx;
	// double		miny;
	// double		maxy;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
}				t_fract;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	int			*img;
	int			fid;
	t_value		value;
	t_fract		point;
}				t_window;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_hsv
{
	double			h;
	double			s;
	double			v;
}				t_hsv;

typedef struct	s_part
{
	double		i;
	double		r;
}				t_part;

int			ft_lfract(t_window *infos);
int			ft_mandel(t_window *infos);
int			ft_julia(t_window *infos);
int			ft_dealkey(int key, t_window *infos);
int			ft_dealmouse(int button, int x, int y, t_window *infos);
t_window	*ft_zoom_mandel(t_window *infos, int x, int y);
t_window	*ft_dezoom_mandel(t_window *infos, int x, int y);
int			ft_color(t_window *infos, int i, int color1);
t_window	*ft_fill_imgcolor(t_window *infos, int i, double x, double y);
int			ft_hsv2rgb(t_hsv hsv);

#endif