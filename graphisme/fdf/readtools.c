/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:56:16 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/23 14:55:13 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'x' || (line[i] >= '0' && line[i] <= '9')
			|| line[i] == ' ' || line[i] == ','
				|| (line[i] >= 'A' && line[i] <= 'F')
					|| (line[i] >= 'a' && line[i] <= 'f') || line[i] == '-')
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

int		ft_check_error(char *full, char *line)
{
	if (ft_check_char(line) == 0)
	{
		ft_free_fullline(full, line);
		return (0);
	}
	if (ft_rd_nbc(line) == -1)
	{
		ft_free_fullline(full, line);
		return (0);
	}
	return (1);
}

void	ft_free_fullline(char *full, char *line)
{
	ft_strdel(&full);
	ft_strdel(&line);
}

char	*ft_fill_full(char *full, char *line, int *lenc)
{
	full = ft_free_join(full, line);
	full = ft_free_join(full, "\n");
	*lenc = ft_rd_nbc(line);
	free(line);
	return (full);
}
