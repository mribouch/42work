/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:09:09 by mribouch          #+#    #+#             */
/*   Updated: 2019/06/24 15:01:42 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_check_square(t_window *infos, t_slider *slide, t_square *sqw
	, t_square *sqb)
{
	if (infos->value.cid == 4)
	{
		ft_init_square(sqw, sqb, slide);
		ft_fill_square(infos, *sqw);
		ft_fill_square(infos, *sqb);
	}
	if (infos->btnp == 1 && ft_in_square(infos, sqb) == 1)
		slide->col_s.v = 0;
	if (infos->btnp == 1 && ft_in_square(infos, sqw) == 1)
	{
		slide->col_s.s = 0;
		slide->col_s.v = 1;
	}
}

int			ft_in_square(t_window *infos, t_square *sq)
{
	if ((infos->cursor.x >= sq->x && infos->cursor.x <= sq->x + sq->size)
		&& (infos->cursor.y >= sq->y && infos->cursor.y <= sq->y + sq->size))
		return (1);
	return (0);
}

void		ft_init_square(t_square *sqw, t_square *sqb, t_slider *slide)
{
	sqw->x = slide->x - 20;
	sqw->size = 10;
	sqw->y = slide->y + 3 - sqw->size / 2;
	sqw->color = 0xFFFFFF;
	sqb->y = sqw->y;
	sqb->x = sqw->x - 15;
	sqb->size = sqw->size;
	sqb->color = 0x000000;
}

t_window	*ft_put_gauge(t_window *infos, t_slider *slide)
{
	infos = ft_putrgbar(infos, slide->x, slide->y, 100);
	infos = ft_putrgbar(infos, slide->x, slide->y + 1, 100);
	infos = ft_putrgbar(infos, slide->x, slide->y + 2, 100);
	infos = ft_putrgbar(infos, slide->x, slide->y + 3, 100);
	infos = ft_putrgbar(infos, slide->x, slide->y + 4, 100);
	return (infos);
}
