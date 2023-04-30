/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:17:35 by bgales            #+#    #+#             */
/*   Updated: 2021/11/04 01:03:01 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dst_cpy;
	char			*src_cpy;

	i = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (dst_cpy > src_cpy)
	{
		while (i < len)
		{
			dst_cpy[len - 1] = src_cpy[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
