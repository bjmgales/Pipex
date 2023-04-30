/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:24:42 by bgales            #+#    #+#             */
/*   Updated: 2021/11/04 01:01:46 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = ft_strlen(dst);
	if (i > dstsize)
		return (dstsize + ft_strlen(src));
	c = 0;
	while (src[c] && i + c < dstsize - 1)
	{
		dst[i + c] = src[c];
		c++;
	}
	if (dstsize <= 0)
	{
		dst[0] = 0;
		return (ft_strlen(src));
	}
	if (dstsize > 0)
		dst[i + c] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[c]));
}
