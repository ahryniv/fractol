/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:41 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/01 22:00:16 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ss;
	char *res;

	ss = (char*)s;
	while (*ss != '\0')
	{
		if (*ss == c)
			res = ss;
		ss++;
	}
	if (*res == c)
		return (res);
	if (*ss == '\0' && c == '\0')
		return (ss);
	return (0);
}
