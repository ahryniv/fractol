/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:44 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 19:07:46 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str2;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		str2 = (char *)malloc(sizeof(*str2) * len + 1);
		if (str2)
		{
			while (i < len)
			{
				str2[i] = f(i, s[i]);
				i++;
			}
			str2[i] = '\0';
			return (str2);
		}
	}
	return (NULL);
}
