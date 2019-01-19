/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:49:22 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 20:39:40 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)str;
	while (n > 0)
	{
		if (*d++ == (unsigned char)c)
			return (d - 1);
		n--;
	}
	return (NULL);
}
