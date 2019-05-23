/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:13:15 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 15:58:39 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WIDTH 320
# define HEIGHT 200

typedef struct	s_wolf
{
	t_coord3d	pos_cam;
	int			angle_cam;
	int			fov;
	int			d_camscreen;

}				t_wolf;

typedef struct	s_coord3d
{
	double		x;
	double		y;
	double		z;
}				t_coord3d;

typedef struct	s_coord2d
{
	double			x;
	double			y;
}				t_coord2d;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	t_coord2d	cursor;
	t_wolf		*data;
}				t_window;

#endif