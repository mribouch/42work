/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:14:59 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/14 14:00:43 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_hex2int(char *hex)
{
    int	result;
	int	i;

	result = 0;
	i = 0;
    while(hex[i] != '\0')
	{
        if(hex[i] >= '0' && hex[i] <= '9')
		{
            result <<= 4;
            result += hex[i] - '0';
        }
        if(hex[i] >= 'a' && hex[i] <= 'f')
		{
            result <<= 4;
            result += hex[i] - 'a' + 10;
        }
        if(hex[i] >= 'A' && hex[i] <= 'F')
		{
            result <<= 4;
            result += hex[i] - 'A'+ 10;
        }
        i++;
    }
    return result;
}

int ft_get_c(char *full)
{
    int index;

    index = 0;
    while (full[index] != '\0')
    {
        if (full[index] == ',')
            return (index + 1);
        index++;
    }
    return (0);
}

int ft_get_s(char *full)
{
    int index;
    int s;

    index = 0;
    s = 0;
    while (full[index] != ' ' && full[index] != '\n' && full[index] != '\0')
    {
        index++;
        s++;
    }
    return (s - 1);
}

int		ft_numwords(char *str)
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

int		ft_lenword(char *str, int index)
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

char	**ft_strsplit_fdf(char *str)
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

void	ft_bblue(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((int *)s)[i] = 0x005B5D;
		i++;
	}
}

void	ft_bcolor(void *s, int color, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((int *)s)[i] = color;
		i++;
	}
}