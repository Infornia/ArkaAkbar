/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:52:12 by cdivry            #+#    #+#             */
/*   Updated: 2014/04/18 19:52:12 by cdivry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_list_push_back(t_list **begin_lst)
{
	t_list	*tmp;
	t_list	*lstcpy;

	if (!begin_lst || !*begin_lst)
		return ;
	tmp = *begin_lst;
	while (tmp)
	{
		lstcpy = ft_lstnew(tmp->content, tmp->content_size);
		if (!lstcpy)
			return ;
		tmp = tmp->next;
		lstcpy->next = tmp;
	}
}

static t_list	*lstcpy(t_list *begin)
{
	t_list	*lstcpy;
	t_list	tmp;

	tmp = *begin;
	lstcpy = &tmp;
	ft_list_push_back(&lstcpy);
	return (begin);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*elem;

	newlst = lstcpy(lst);
	elem = newlst;
	while (elem)
	{
		elem = f(elem);
		elem = elem->next;
	}
	return (newlst);
}
