/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:41 by ahryniv           #+#    #+#             */
/*   Updated: 2016/11/29 20:58:56 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	ss = (char*)s;
	i = 0;
	while (*ss != '\0')
	{
		if (*ss == c)
			return (ss);
		ss++;
	}
	if (*ss == c)
		return (ss);
	return (NULL);
}
