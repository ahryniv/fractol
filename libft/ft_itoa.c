/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:05:16 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 20:39:07 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*f_positive(long n)
{
	size_t	size;
	int		i;
	char	*str;

	i = 0;
	size = count(n);
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		i = size;
		str[i] = '\0';
		i--;
		while (i >= 0)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
		return (str);
	}
	return (NULL);
}

static char	*f_negative(long n)
{
	size_t	size;
	int		i;
	char	*str;

	i = 0;
	size = count(n);
	n = -n;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		i = size;
		str[i] = '\0';
		i--;
		while (i > 0)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
		str[i] = '-';
		return (str);
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	long	n1;

	n1 = n;
	if (n1 < 0)
		return (f_negative(n1));
	else
		return (f_positive(n1));
}
