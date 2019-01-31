/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:53:40 by myener            #+#    #+#             */
/*   Updated: 2018/11/27 16:13:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src2;
	char		*dst2;
	size_t		i;

	src2 = (const char*)src;
	dst2 = (char*)dst;
	i = 0;
	if (src2 < dst2)
	{
		while (len--)
			dst2[len] = src2[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
