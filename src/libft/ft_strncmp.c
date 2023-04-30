/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:56:14 by bgales            #+#    #+#             */
/*   Updated: 2021/10/23 17:19:07 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while ((*s1 || *s2) && (counter < n))
	{
		if ((*s1 > *s2) || (*s1 < *s2))
			return (*s1 - *s2);
		s1++;
		s2++;
		counter++;
	}
	return (0);
}
