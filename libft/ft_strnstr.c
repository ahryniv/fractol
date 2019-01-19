/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 20:33:49 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 20:41:25 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*begin;
	const char	*pattern;
	const char	*tmp;

	tmp = big;
	if (*big == '\0' && *little == '\0')
		return ((char *)big);
	while (*big && tmp + len)
	{
		pattern = little;
		begin = big;
		while (*big && *pattern && *big == *pattern && big < tmp + len)
		{
			big++;
			pattern++;
		}
		if (!*pattern)
			return ((char *)begin);
		big = begin + 1;
	}
	return (NULL);
}
