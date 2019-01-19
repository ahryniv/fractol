/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:07:55 by ahryniv           #+#    #+#             */
/*   Updated: 2017/04/28 20:38:14 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		words++;
		while (str[i] == c)
			i++;
	}
	return (words);
}

static char	**create_matrix(char **array, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < word_count(str, c))
	{
		while (str[i] != c && str[i] != '\0')
		{
			j++;
			i++;
		}
		if (!(array[k] = (char *)malloc(sizeof(char) * (j + 1))))
			return (0);
		while (str[i] == c)
		{
			j = 0;
			i++;
		}
		k++;
	}
	array[k] = 0;
	return (array);
}

static char	**fill_matrix(char **array, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < word_count(str, c))
	{
		while (str[i] != c && str[i] != '\0')
		{
			array[k][j] = str[i];
			j++;
			i++;
		}
		array[k][j] = '\0';
		while (str[i] == c)
		{
			j = 0;
			i++;
		}
		k++;
	}
	return (array);
}

static char	*leading_spaces(char const *str, char c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (*str2 == c)
		str2++;
	return (str2);
}

char		**ft_strsplit(char const *s, char c)
{
	char **array;
	char *str2;

	if (s)
	{
		str2 = leading_spaces(s, c);
		if (!(array = (char **)malloc(sizeof(char *) *
						(word_count(str2, c) + 1))))
			return (0);
		array = create_matrix(array, str2, c);
		array = fill_matrix(array, str2, c);
		return (array);
	}
	return (0);
}
