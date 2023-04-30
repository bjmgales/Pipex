/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:02 by bgales            #+#    #+#             */
/*   Updated: 2021/10/26 15:33:18 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1tmp;
	unsigned char	*s2tmp;

	s1tmp = (void *)(s1);
	s2tmp = (void *)(s2);
	index = 0;
	while (index < n)
	{
		if ((s1tmp[index] > s2tmp[index]) || (s1tmp[index] < s2tmp[index]))
			return ((int)(s1tmp[index] - s2tmp[index]));
		index++;
	}
	return (0);
}
