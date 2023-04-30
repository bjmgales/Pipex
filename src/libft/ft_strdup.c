/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:23:32 by bgales            #+#    #+#             */
/*   Updated: 2021/11/18 15:12:13 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cpy == (NULL))
		return (NULL);
	ft_strlcpy(cpy, s, ft_strlen(s) + 1);
	return (cpy);
}
