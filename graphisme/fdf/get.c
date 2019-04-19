/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:14:18 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/19 14:47:29 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_fill_res(char *res, char *full, int i, int k)
{
	int ret;

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

int			*ft_get_img(int *img, void *img_ptr, t_window *infos)
{
	int bpp;
	int s_l;
	int endian;

	img = (int*)mlx_get_data_addr(img_ptr, &bpp, &s_l, &endian);
	ft_bzero(img, infos->width * infos->height);
	return (img);
}

char		**ft_get_col(char **allpoint, char **col)
{
	int		i;

	i = 0;
	while (allpoint[i] != 0)
		i++;
	if (!(col = malloc(sizeof(char*) * (i + 1))))
		return (0);
	i = 0;
	while (allpoint[i] != 0)
	{
		if (ft_get_c(allpoint[i]) == 0)
		{
			if (!(col[i] = (char *)malloc(sizeof(char) * 9)))
				return (0);
			col[i] = ft_strcpy(col[i], "0xFFFFFF");
		}
		else
		{
			col[i] = ft_strsub(allpoint[i], ft_get_c(allpoint[i]),
				ft_strlen(allpoint[i]) - ft_get_c(allpoint[i]));
		}
		i++;
	}
	col[i] = 0;
	return (col);
}

int			ft_get_num(char *full, int k)
{
	char	*res;
	int		i;
	int		ret;
	int		sign;

	i = 0;
	sign = 0;
	while (full[k] >= '0' && full[k++] <= '9')
		i++;
	k = k - i;
	if (full[k - 1] == '-')
		sign = 1;
	if (!(res = malloc(sizeof(char) * (i + 1 + sign))))
		return (0);
	i = 0;
	if (sign == 1)
	{
		res[0] = '-';
		i++;
	}
	ret = ft_fill_res(res, full, i, k);
	free(res);
	return (ret);
}
