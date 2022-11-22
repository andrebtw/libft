/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:52:48 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/22 14:34:17 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_free_tab(int i, char **r_string)
{
	while (i >= 0)
	{
		free(r_string[i]);
		i--;
	}
	free(r_string);
}

char	*ft_malloc_string2(char const *s, char c, int i, int n)
{
	int		r_string_index;
	char	*r_string;

	r_string_index = 0;
	if (i)
		i--;
	n = ft_skip_begin(s, c, i) - 1;
	i = ft_add_i(s, c, i);
	r_string = (char *) malloc (i - n + 1);
	if (!r_string)
		return (NULL);
	while (i > ++n)
		r_string[r_string_index++] = s[n];
	r_string[r_string_index] = '\0';
	return (r_string);
}

char	**ft_empty_str(void)
{
	char	**r_string;

	r_string = (char **) malloc (sizeof(char **));
	if (!r_string)
		return (NULL);
	r_string[0] = NULL;
	return (r_string);
}

char	**ft_split_return(const char *s, char c)
{
	char	**r_string;
	int		i;

	if (!s || !s[0])
	{
		r_string = ft_empty_str();
		return (r_string);
	}
	r_string = (char **) malloc ((
				ft_malloc_size_tab(s, c) + 1) * sizeof(char **));
	if (!r_string)
		return (NULL);
	i = 0;
	while (i < ft_malloc_size_tab(s, c))
	{
		r_string[i] = ft_malloc_string(s, c, i);
		if (!r_string)
		{
			ft_free_tab(i, r_string);
			return (NULL);
		}
		i++;
	}
	r_string[i] = NULL;
	return (r_string);
}
