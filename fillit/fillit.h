/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:45:54 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/24 15:15:11 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tetri
{
	char			**tetri;
	char			key;
	int				width;
	int				height;
	int				x;
	int				y;
	struct s_tetri	*next;
}				t_tetri;

int				get_next_line(int fd, char **line);
char			*ft_tetrisvalid(int fd);
int				ft_check_neighbour(char *str);
int				ft_num_tetri(char *str);
t_tetri			*ft_get_tetriminos(char *str);
int				ft_sqrt_fillit(int nb);
void			ft_print_map(char **map);
char			**ft_create_map(int size_m);
int				ft_get_map_size(char *str);
t_tetri			*ft_put_up_left(t_tetri *begin);
char			**ft_solve(char **map, t_tetri *begin, int s_map);
int				ft_end_tetri(int nbl);

#endif
