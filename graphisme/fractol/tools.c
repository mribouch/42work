/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:08:51 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/01 17:58:42 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_lfract(t_window *infos)
{
	if (infos->fid == 1)
		ft_mandel(infos);
	else if (infos->fid == 2)
		ft_julia(infos);
	return (0);
}