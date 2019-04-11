/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:32:41 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/11 14:55:01 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_inmap(t_window *infos)
{
	free(infos->mapinf);
	mlx_destroy_image(infos->mlx_ptr, infos->img_ptr);
	mlx_destroy_window(infos->mlx_ptr, infos->win_ptr);
	free(infos->mlx_ptr);
	free(infos);
}

void		ft_free_dchar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char		*ft_free_join(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	ft_strdel(&s1);
	return (s3);
}

static void	ft_free_map(t_window *infos)
{
	int	i;
	int	s_map;

	s_map = infos->mapinf->height;
	i = 0;
	while (i < s_map)
		free(infos->mapinf->map[i++]);
	free(infos->mapinf->map);
}

void		ft_free_infos(t_window *infos)
{
	mlx_destroy_image(infos->mlx_ptr, infos->img_ptr);
	mlx_destroy_window(infos->mlx_ptr, infos->win_ptr);
	ft_free_map(infos);
	free(infos->vertices);
	free(infos->iso);
	free(infos->state);
	free(infos->mapinf);
	free(infos);
}
