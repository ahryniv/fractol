/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:06:46 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 19:06:48 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str2;

	i = 0;
	if (s)
	{
		str2 = (char *)malloc(sizeof(*str2) * len + 1);
		if (str2)
		{
			while (len > 0)
			{
				str2[i] = s[start + i];
				i++;
				len--;
			}
			str2[i] = '\0';
			return (str2);
		}
	}
	return (NULL);
}
