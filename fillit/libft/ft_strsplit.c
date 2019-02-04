/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:11:23 by myener            #+#    #+#             */
/*   Updated: 2018/11/27 16:11:48 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		notc(const char *cnt, int c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (cnt[i])
	{
		if (cnt[i] != c && cnt[i] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int		charcount(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

static char		**fightthepower(char **tab, const char *str, int c)
{
	int		i;
	int		j;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (!(tab[i] = malloc(sizeof(char) * (charcount(str, c) + 1))))
				return (NULL);
			j = 0;
			while (*str != c && *str != '\0')
			{
				tab[i][j] = *str;
				j++;
				str++;
			}
			tab[i][j] = '\0';
			i++;
		}
		if (*str)
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(*tab) * (notc(s, c) + 1))))
		return (NULL);
	return (fightthepower(tab, s, c));
}
