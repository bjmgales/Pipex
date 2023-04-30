/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:51:34 by bgales            #+#    #+#             */
/*   Updated: 2021/10/30 16:22:01 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	j = start;
	if (start + len > ft_strlen(s))
		len = start + len - ft_strlen(&s[start]);
	if (start < 0 || len < 0 || s == (NULL))
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(&s[start]) + 1;
	tmp = malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	while (j < (start + len))
		tmp[i++] = ((char *)(s))[j++];
	tmp[i++] = '\0';
	return (tmp);
}
