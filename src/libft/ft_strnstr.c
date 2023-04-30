/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:59:05 by bgales            #+#    #+#             */
/*   Updated: 2021/11/23 20:42:55 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;
	size_t			len_needle;

	n = 0;
	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (n + len_needle > len)
			return (0);
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		haystack++;
		n++;
	}
	return (0);
}
