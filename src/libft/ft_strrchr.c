/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:07:49 by bgales            #+#    #+#             */
/*   Updated: 2021/11/22 15:26:15 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*cpy;

	cpy = (char *)s;
	index = 0;
	while (cpy[index] != '\0')
		index++;
	while (index >= 0)
	{
		if (cpy[index] == (char)c)
			return (&cpy[index]);
		index--;
	}
	return (NULL);
}
