/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:08:05 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 19:08:07 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ftt(size_t size, char *new, char const *old, size_t old_iter)
{
	size_t	f;

	f = 0;
	while (f < size)
	{
		new[f] = old[old_iter];
		f++;
		old_iter++;
	}
	new[f] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	t;
	size_t	f;
	size_t	size;
	char	*str;

	if (s)
	{
		i = 0;
		f = 0;
		t = ft_strlen(s) - 1;
		while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
			i++;
		while ((s[t] == ' ') || (s[t] == '\t') || (s[t] == '\n'))
			t--;
		size = (ft_strlen(s) - i - (ft_strlen(s) - t) + 1);
		if (i == ft_strlen(s))
			size = 0;
		str = (char *)malloc(sizeof(*str) * size + 1);
		if (str)
			return (ftt(size, str, s, i));
	}
	return (NULL);
}
