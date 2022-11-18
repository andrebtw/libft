/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:23:48 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/18 03:23:53 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

//"HelloWorld "
int	ft_malloc_size_tab(char const *s, char c)
{
	int		i;
	int		malloc_size;
	int		found_char;

	i = 0;
	malloc_size = 1;
	while (s[i] != '\0')
	{
		found_char = 0;
		if (s[i] && (!i && s[0] == c))
			while (s[i] && s[i] == c)
				i++;
		if (!s[i])
			return (malloc_size + 1);
		if (s[i] && s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			malloc_size++;
			found_char = 1;
		}
		if (!found_char)
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
	int		r_string_index;

	i = 0;
	r_string_index = 0;
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
		i++;
	}
	if (i)
		i--;
	n = ft_skip_begin(s, c, i);
	i = ft_add_i(s, c, i);
	r_string = (char *) malloc (i - n + 1);
	while (i > n)
	{
		r_string[r_string_index] = s[n];
		n++;
		r_string_index++;
	}
	r_string[r_string_index] = '\0';
	return (r_string);
}

char	**ft_split(char const *s, char c)
{
	char	**r_string;
	int		i;

	r_string = (char **) malloc ((ft_malloc_size_tab(s, c) + 1) * sizeof(char **));
	if (!r_string)
		return (NULL);
	i = 0;
	while (i < ft_malloc_size_tab(s, c))
	{
		r_string[i] = ft_malloc_string(s, c, i);
		if (!r_string)
		{
			while (i >= 0)
			{
				free(r_string[i]);
				i--;
			}
			free(r_string);
			return (NULL);
		}
		i++;
	}
	r_string[i] = NULL;
	return (r_string);
}

#include <stdio.h>
int	main(void)
{
	char **test = ft_split("     ", ' ');
	int i = 0;
	while (test[i] != NULL)
	{
		printf("%s\n", test[i]);
		i++;
	}
	while (i >= 0)
	{
		free(test[i]);
		i--;
	}
	free(test);
	return (0);
}
