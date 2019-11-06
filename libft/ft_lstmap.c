/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:25:27 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/04 21:49:14 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	tmp = (*f)(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (new == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (new == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
