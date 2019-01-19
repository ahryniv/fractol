/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:53:21 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/06 20:09:43 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*d;

	d = *alst;
	if (*alst && d)
	{
		while (d)
		{
			next = d->next;
			del(d->content, d->content_size);
			free(d);
			d = next;
		}
		*alst = NULL;
	}
}
