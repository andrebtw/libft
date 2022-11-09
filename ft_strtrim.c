/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:35:19 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/09 12:29:39 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_strlen_int(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

static int	ft_skip_begin(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found_char;

	i = 0;
	while (s1[i] != '\0')
	{
		found_char = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				found_char = 1;
			j++;
		}
		if (found_char == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_skip_end(char const *s1, char const *set, int count)
{
	int	i;
	int	j;
	int	found_char;

	i = 0;
	while (s1[count + i] != '\0')
	{
		found_char = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[count + i] == set[j])
				found_char = 1;
			j++;
		}
		if (found_char == 0)
			return (count);
		i++;
	}
	if (s1[count + i] == '\0')
		return (count + i);
	return (count);
}
#include <stdio.h>
char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	k;
	char *r_string;

	r_string = (char *) malloc (ft_strlen_int(s1) + 1);
	if (r_string == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		k = ft_skip_end(s1, set, k);
		if (i == 0)
			i = ft_skip_begin(s1, set);
		r_string[k] = s1[i];
		k++;
		i++;
	}
	r_string[k] = '\0';
	return (r_string);
}


#include <stdio.h>
int	main(void)
{
	char *test = ft_strtrim("z42 networkzbzzzzzzzzzzzzzzzzzzzz", "z");
	printf("%s", test);
	return (0);
}