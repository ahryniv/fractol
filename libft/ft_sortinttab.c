/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:49:34 by ahryniv           #+#    #+#             */
/*   Updated: 2016/12/07 22:17:41 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sortinttab(int *tab, int n)
{
	int	i;
	int	j;
	int	bub;

	i = 0;
	if (!tab)
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				bub = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = bub;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
