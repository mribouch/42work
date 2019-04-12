/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:36:13 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/11 20:10:39 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_color(char *line, int i)
{
	int	j;
	int	c;

	j = 0;
	c = 10;
	if ((line[i] >= 'a' && line[i] <= 'f') ||
	(line[i] >= 'A' && line[i] <= 'F'))
	{
		while (c != 0)
		{
			if (line[i] == ',')
				return (1);
			i--;
			c--;
		}
	}
	if (j == 1)
		return (1);
	return (0);
}

int		ft_parse_error(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == ',') && ((line[i - 1] < '0' || line[i - 1] > '9') ||
			line[i + 2] != 'x'))
			return (0);
		if ((line[i] == 'x') && (line[i - 1] != '0' || line[i - 2] != ','))
			return (0);
		if (line[i] == '-' && (line[i + 1] < '0' || line[i + 1] > '9'))
			return (0);
		if (((line[i] >= 'a' && line[i] <= 'f') ||
		(line[i] >= 'A' && line[i] <= 'F')) &&
		ft_check_color(line, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_parse_line(char *full, char *line, int lenc)
{
	if (ft_parse_error(line) == 0)
	{
		ft_free_fullline(full, line);
		return (0);
	}
	if (ft_check_char(line) == 0)
	{
		ft_free_fullline(full, line);
		return (0);
	}
	if (ft_rd_nbc(line) == -1 || lenc != ft_rd_nbc(line))
	{
		ft_free_fullline(full, line);
		return (0);
	}
	return (1);
}

int		ft_check_return(char *line, char *full)
{
	if (ft_strlen(line) == 0)
		return (0);
	if (ft_parse_error(line) == 0)
	{
		ft_free_fullline(full, line);
		return (0);
	}
	return (1);
}
