/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:14:59 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/25 15:33:10 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_hex2int(char *hex)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			result <<= 4;
			result += hex[i] - '0';
		}
		if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			result <<= 4;
			result += hex[i] - 'a' + 10;
		}
		if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			result <<= 4;
			result += hex[i] - 'A' + 10;
		}
		i++;
	}
	return (result);
}

int	ft_get_c(char *full)
{
	int	index;

	index = 0;
	while (full[index] != '\0')
	{
		if (full[index] == ',')
			return (index + 1);
		index++;
	}
	return (0);
}

int	ft_rd_nbc(char *full)
{
	int	i;
	int	nbc;
	int	len;

	i = 0;
	nbc = 0;
	len = ft_strlen(full);
	while (full[i] == ' ')
		i++;
	while (full[i] != '\n' && full[i] != '\0')
	{
		if (full[i] == ' ')
		{
			while (full[i] == ' ')
				i++;
			nbc++;
		}
		i++;
	}
	if (full[len - 1] == ' ')
		return (-1);
	return (nbc + 1);
}

int	ft_rd_nbl(char *full)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = 0;
	while (full[i] != '\0')
	{
		if (full[i] == '\n')
			nbl++;
		i++;
	}
	return (nbl);
}
