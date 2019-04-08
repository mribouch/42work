/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:56:16 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/08 17:05:47 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_fullline(char *full, char *line)
{
	free(full);
	free(line);
}

char	*ft_fill_full(char *full, char *line, int *lenc)
{
	full = ft_free_join(full, line);
	full = ft_free_join(full, "\n");
	*lenc = ft_rd_nbc(line);
	free(line);
	return (full);
}
