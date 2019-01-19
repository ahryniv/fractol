/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:00 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 20:39:19 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!lst && f)
		return (NULL);
	tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	if (!tmp)
		return (NULL);
	tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
