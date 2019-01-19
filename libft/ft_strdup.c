/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:26:30 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 17:27:56 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ss;
	size_t	i;

	i = 0;
	ss = malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (ss)
	{
		while (i < ft_strlen(s1))
		{
			ss[i] = s1[i];
			i++;
		}
		ss[i] = '\0';
	}
	return (ss);
}
