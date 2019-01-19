/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:26:32 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 22:13:18 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *ss)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!ss)
		return (NULL);
	i = 0;
	len = ft_strlen(ss);
	new = malloc(len + 1);
	while (ss[i] != '\0')
	{
		new[i] = ss[len - 1 - i];
		i++;
	}
	return (new);
}
