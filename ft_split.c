4/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:21:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/15 15:35:23 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void	ft_free_all(char **string, int i)
{
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
}

static int	ft_isempty(char *string)
{
	if (string[0] != 0)
		return (1);
	return (0);
}

static char	**ft_malloced(char const *s)
{
	char	**r_string;
	int		i;

	i = 0;
	r_string = (char **) malloc ((ft_strlen(s) * ft_strlen(s) + 1) * sizeof(char **));
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

char	**ft_split(char const *s, char c)
{
	char	**r_string;
	int		i;
	int		j;
	int		k;

	r_string = ft_malloced(s);
	if (!r_string)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if  (s[i] == c && s[i + 1] == c)
			i++;
		else
		{
			r_string[k][j] = s[i];
			i++;
			j++;
		}
		if (s[i] == c && s[i + 1] != c)
		{
			i++;
			if (ft_isempty(r_string[0]) != 0)
			{
				r_string[k][j] = '\0';
				k++;
			}
			j = 0;
		}
	}
	r_string[k][j] = '\0';
	if (r_string[k][0])
		k++;
	r_string[k] = NULL;
	return (r_string);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**splitted = ft_split("test ", ' ');
	int i = 0;
	while (splitted[i] != NULL)
	{
		printf("[%s]", splitted[i]);
		i++;
	}
	printf("%s", splitted[i]);
	return (0);
}*/
