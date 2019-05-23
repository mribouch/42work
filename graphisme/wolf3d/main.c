/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:11:08 by mribouch          #+#    #+#             */
/*   Updated: 2019/05/22 15:19:06 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("usage: ./wolf3d FileName");
	else
	{
		ft_putendl(av[1]);
	}
	return (0);
}