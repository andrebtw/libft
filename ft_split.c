/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:21:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/15 16:28:23 by anrodri2         ###   ########.fr       */
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
