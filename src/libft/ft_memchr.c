/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:30:56 by bgales            #+#    #+#             */
/*   Updated: 2021/10/26 17:50:24 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	char			*scpy;

	scpy = (char *)(s);
	counter = 0;
	while (counter < n)
	{
		if (scpy[counter] == (char)c)
		{
			return ((char *)(scpy + counter));
		}
		counter++;
	}
	return (0);
}
