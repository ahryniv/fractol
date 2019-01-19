/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:13:28 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/05 20:10:27 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		j;
	char	*b;

	b = (char*)big;
	if (ft_strlen(little) == 0)
		return (b);
	while (*b != '\0')
	{
		j = 0;
		if (*b == little[j])
		{
			while ((b[j] == little[j]) && little[j] != '\0')
			{
				j++;
			}
			if (little[j] == '\0')
				return (b);
		}
		b++;
	}
	return (NULL);
}
