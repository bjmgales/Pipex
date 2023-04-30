/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:47:00 by bgales            #+#    #+#             */
/*   Updated: 2021/11/06 00:57:31 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	ptr = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			del(new->next);
			return (0);
		}
		lst = lst->next;
		new = new-> next;
	}
	new->next = NULL;
	return (ptr);
}
