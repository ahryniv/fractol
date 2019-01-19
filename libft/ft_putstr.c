/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:49:08 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 17:27:15 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t	i;
	char	c;

	i = 0;
	if (s)
	{
		while (i < ft_strlen(s))
		{
			c = s[i];
			write(1, &c, 1);
			i++;
		}
	}
}