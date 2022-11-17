/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:21:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/15 21:20:56 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
/*
static void	ft_free_all(char **string, int i)
{
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
}

static char	**ft_malloced(char const *s)
{
	char	**r_string;
	int		i;

	i = 0;
	r_string = (char **) malloc (
			(ft_strlen(s) * ft_strlen(s) + 2) * sizeof(char **));
	if (!r_string)
		return (NULL);
	while ((size_t)i <= ft_strlen(s) + 1)
	{
		r_string[i] = (char *) malloc ((ft_strlen(s) + 1));
		if (!r_string[i])
		{
			ft_free_all(r_string, i);
			return (NULL);
		}
		i++;
	}
	ft_bzero(r_string[0], 1);
	return (r_string);
}

char	**ft_check_end(char **r_string, int k, int j)
{
	r_string[k][j] = '\0';
	if (r_string[k][0])
		k++;
	r_string[k] = NULL;
	return (r_string);
}

char	**ft_split_main(char const *s, char c, char **r_string, int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c && s[i + 1] == c))
		{
			r_string[k][j] = s[i];
			j++;
		}
		i++;
		if (s[i] == c && s[i + 1] != c)
		{
			i++;
			if (r_string[0][0] != 0)
			{
				r_string[k][j] = '\0';
				k++;
			}
			j = 0;
		}
	}
	return (ft_check_end(r_string, k, j));
}

char	**ft_split(char const *s, char c)
{
	char	**r_string;
	int		i;

	r_string = ft_malloced(s);
	if (!r_string)
		return (NULL);
	i = 0;
	r_string = ft_split_main(s, c, r_string, i);
	return (r_string);
}
*/

static void	ft_free_all(char **string, int i)
{
	while (i != -1)
	{
		free(string[i]);
		i--;
	}
	free(string);
}

static char	*ft_fill(char const *s, char c, int n)
{
	int		i;
	char	*string;
	int		string_i;

	i = 0;
	string_i = 0;
	while (n != 0 && s[i])
		if (s[i++] == c && n--)
			while (s[i] == c && s[i])
				i++;
	n = i;
	while (s[n] != c && s[n])
		n++;
	string = (char *) malloc ((n - i + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (i != n)
	{
		string[string_i] = s[i];
		i++;
		string_i++;
	}
	string[string_i] = '\0';
	return (string);
}

static int		ft_malloc_size(char const *s, char c)
{
	int	i;
	int	char_counter;

	char_counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			char_counter++;
			while (s[i] == c && s[i])
				i++;
		}
		i++;
	}
	if (char_counter == 1)
		return (2);
	return (char_counter);
}

char	**ft_split(char const *s, char c)
{
	char	**r_string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	r_string = (char **) malloc (ft_malloc_size(s, c) + 1);
	if (!r_string)
		return (NULL);
	while (i < ft_malloc_size(s, c))
	{
		r_string[i] = ft_fill(s, c, i);
		if (!r_string[i])
			ft_free_all(r_string, i - 1);
		i++;
	}
	r_string[i] = NULL;
	return (r_string);
}
/*
#include <stdio.h>
int	main(int args, char **argv)
{
	char **test = ft_split(argv[1], ' ');
	int i = 0;
	while (test[i] != NULL)
	{
		printf("%s\n", test[i]);
		i++;
	}
	printf("%p\n", test[i]);
	ft_free_all(test, i - 1);
	return 0;
}*/
