/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:27 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 19:07:28 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*str2;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		str2 = (char *)malloc(sizeof(*str2) * len + 1);
		if (str2)
		{
			while (i < len)
			{
				str2[i] = f(s[i]);
				i++;
			}
			str2[i] = '\0';
			return (str2);
		}
	}
	return (NULL);
}
