/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:30:28 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/23 16:18:59 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_num_tetri(char *str)
{
	int	nbc;
	int	sep;
	int	i;

	i = 0;
	sep = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			sep++;
		i++;
	}
	nbc = i - sep;
	return (nbc / 20);
}

int	ft_sqrt_fillit(int nb)
{
	int	res;
	int i;

	i = 0;
	res = 0;
	if (nb < 0)
		return (0);
	while (res != nb)
	{
		if (res > nb)
			return (i);
		i++;
		res = i * i;
		if (i == 50000)
			return (0);
	}
	return (i);
}
