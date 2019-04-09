/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:36:13 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/09 18:37:29 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parse_error(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == ',') && ((line[i - 1] < '0' || line[i - 1] > '9') ||
			line[i + 2] != 'x'))
			return (0);
		if ((line[i] == 'x') && (line[i - 1] != '0' || line[i - 2] != ','))
			return (0);
		if (line[i] == '-' && (line[i + 1] < '0' || line[i + 1] > '9'))
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
