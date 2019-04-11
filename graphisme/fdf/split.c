/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:26:13 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/11 14:46:07 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_numwords(char *str)
{
	int p;
	int i;

	p = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 || str[i] == '\n')
		{
			while ((str[i]) && (str[i] == 32 || str[i] == '\n'))
				i++;
		}
		if ((str[i]) && (str[i] != 32 && str[i] != '\n'))
		{
			p++;
			while ((str[i]) && (str[i] != 32 && str[i] != '\n'))
				i++;
		}
	}
	return (p);
}

static int	ft_lenword(char *str, int index)
{
	int len;

	len = 0;
	while (str[index] != '\0' && str[index] != 32 && str[index] != '\n')
	{
		len++;
		index++;
	}
	return (len);
}

char		**ft_strsplit_fdf(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(split = malloc(sizeof(char*) * ft_numwords(str) + 1)))
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == 32 || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if (!(split[j] = malloc(sizeof(char) * (ft_lenword(str, i) + 1))))
				return (0);
			while (str[i] != '\0' && str[i] != '\n' && str[i] != 32)
				split[j][k++] = str[i++];
			split[j++][k] = '\0';
		}
	}
	split[j] = 0;
	return (split);
}
