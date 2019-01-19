/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:14:57 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 17:33:53 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		slen;
	size_t	dlen;
	int		k;
	int		i;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	k = size - dlen - 1;
	while (i < k)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	if (dlen < size)
		return (slen + dlen);
	return (size + slen);
}
