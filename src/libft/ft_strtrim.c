/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:26:04 by bgales            #+#    #+#             */
/*   Updated: 2022/06/07 15:45:51 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	true_char(const char tested, const char *set)
{
	while (*set != '\0')
	{
		if (*set == tested)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*finally_trimmed;
	size_t	start;
	size_t	end;

	start = 0;
	if (set == NULL)
		return ((char *)(s1));
	if ((void *)s1 == NULL)
		return (ft_strdup(""));
	while (s1[start] != '\0' && true_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && true_char(s1[end - 1], set))
		end--;
	finally_trimmed = ft_substr(s1, start, (end - start));
	free (s1);
	return (finally_trimmed);
}
