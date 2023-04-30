/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:21:10 by bgales            #+#    #+#             */
/*   Updated: 2022/06/07 15:51:29 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	charcount(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	size_t		len;
	size_t		i;
	const char	*start;
	char		**split;

	i = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(((charcount(s, c)) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s && *s != c && (int)len++ != -1)
			s++;
		if (*(s - 1) != c)
			split[i++] = ft_substr(start, 0, len);
	}
	split[i] = 0;
	return (split);
}
