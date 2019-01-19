/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:13 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 20:40:26 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*j;

	i = 0;
	if (s1 && s2)
	{
		j = (char *)malloc(sizeof(*j) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (j)
		{
			while (s1[i] != '\0')
			{
				j[i] = s1[i];
				i++;
			}
			while (s2[i - ft_strlen(s1)] != '\0')
			{
				j[i] = s2[i - ft_strlen(s1)];
				i++;
			}
			j[i] = '\0';
			return (j);
		}
	}
	return (NULL);
}
