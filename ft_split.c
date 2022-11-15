/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:21:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/15 12:59:54 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**r_string;
	int		i;
	int		j;
	int		k;

	r_string = (char **) malloc (2000);
	r_string[0] = (char *) malloc (50);
	r_string[1] = (char *) malloc (50);
	r_string[2] = (char *) malloc (50);
	r_string[3] = (char *) malloc (50);
	r_string[4] = (char *) malloc (50);
	r_string[5] = (char *) malloc (50);
	r_string[6] = (char *) malloc (50);
	r_string[7] = (char *) malloc (50);
	r_string[8] = (char *) malloc (50);
	r_string[9] = (char *) malloc (50);
	r_string[10] = (char *) malloc (50);
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
			if (r_string[0][0])
			{
				r_string[k][j] = '\0';
				k++;
			}
			j = 0;
		}
	}
	if (r_string[1][0])
		r_string[k] = NULL;
	else if (r_string[0][0])
		r_string[k + 1] = NULL;
	return (r_string);
}

#include <stdio.h>
int	main(void)
{
	char	**splitted = ft_split("      split       this for   me  !       ", ' ');
	int i = 0;
	while (splitted[i] != NULL)
	{
		printf("[%s]", splitted[i]);
		i++;
	}
	printf("%s", splitted[5]);
	return (0);
}
