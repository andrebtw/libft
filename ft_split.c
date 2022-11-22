/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:23:48 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/22 14:33:57 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_malloc_size_tab(char const *s, char c)
{
	int		i;
	int		malloc_size;

	i = 0;
	malloc_size = 1;
	while (s[i])
	{
		if (s[i] && (!i && s[0] == c))
			while (s[i] && s[i] == c)
				i++;
		if (s[i] && s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			malloc_size++;
		}
		else if (s[i])
			i++;
	}
	if (s[i - 1] == c)
		return (malloc_size - 1);
	return (malloc_size);
}

int	ft_skip_begin(char const *s, char c, int i)
{
	if (s[i] && i == 0)
	{
		if (s[i] == c)
			while (s[i] && s[i] == c)
				i++;
	}
	return (i);
}

int	ft_add_i(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	if (s[i] && !i)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}

char	*ft_malloc_string(char const *s, char c, int n)
{
	char	*r_string;
	int		i;

	i = 0;
	if (s[0] == c)
		n++;
	while (s[i] && n != 0)
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			n--;
		}
		if (s[i])
			i++;
	}
	r_string = ft_malloc_string2(s, c, i, n);
	if (!r_string)
		return (NULL);
	return (r_string);
}

char	**ft_split(const char *s, char c)
{
	char	**r_string;

	r_string = ft_split_return(s, c);
	if (!r_string)
		return (NULL);
	return (r_string);
}
