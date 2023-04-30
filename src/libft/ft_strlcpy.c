/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:20:50 by bgales            #+#    #+#             */
/*   Updated: 2021/11/23 13:36:55 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = ft_strlen(src);
	c = 0;
	if (dstsize < 1)
		return (i);
	while (c < dstsize - 1)
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
