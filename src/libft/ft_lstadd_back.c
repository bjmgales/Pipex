/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 01:09:24 by bgales            #+#    #+#             */
/*   Updated: 2021/11/06 18:14:26 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (alst)
	{
		if (*alst)
		{
			tmp = ft_lstlast(*alst);
			tmp->next = new;
		}
	}
	if (*alst == NULL)
		*alst = new;
	return ;
}
