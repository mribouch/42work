/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:30:15 by myener            #+#    #+#             */
/*   Updated: 2018/11/29 16:14:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	int	i;
	int	j;

	if (!*find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 1;
		if (str[i] == find[0])
		{
			while (find[j] != '\0' && str[i + j] == find[j] && (i + j) < len)
				j++;
			if (find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
