/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:14:26 by bgales            #+#    #+#             */
/*   Updated: 2021/11/06 18:14:31 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;

	todel = *lst;
	while (todel != NULL)
	{
		ft_lstdelone(todel, del);
		todel = todel->next;
	}
	*lst = NULL;
	return ;
}
