4/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:21:06 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/15 14:47:17 by anrodri2         ###   ########.fr       */
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

	r_string = (char **) malloc (9000000);
	r_string[0] = (char *) malloc (5000);
	r_string[1] = (char *) malloc (5000);
	r_string[2] = (char *) malloc (5000);
	r_string[3] = (char *) malloc (5000);
	r_string[4] = (char *) malloc (5000);
	r_string[5] = (char *) malloc (5000);
	r_string[6] = (char *) malloc (5000);
	r_string[7] = (char *) malloc (5000);
	r_string[8] = (char *) malloc (5000);
	r_string[9] = (char *) malloc (5000);
	r_string[10] = (char *) malloc (5000);
	r_string[11] = (char *) malloc (5000);
	r_string[12] = (char *) malloc (5000);
	r_string[13] = (char *) malloc (5000);
	r_string[14] = (char *) malloc (5000);
	r_string[15] = (char *) malloc (5000);
	r_string[16] = (char *) malloc (5000);
	r_string[17] = (char *) malloc (5000);
	r_string[18] = (char *) malloc (5000);
	r_string[19] = (char *) malloc (5000);
	r_string[20] = (char *) malloc (5000);
	r_string[21] = (char *) malloc (5000);
	r_string[22] = (char *) malloc (5000);
	r_string[23] = (char *) malloc (5000);
	r_string[24] = (char *) malloc (5000);
	r_string[25] = (char *) malloc (5000);
	r_string[26] = (char *) malloc (5000);
	r_string[27] = (char *) malloc (5000);
	r_string[28] = (char *) malloc (5000);
	r_string[29] = (char *) malloc (5000);
	r_string[30] = (char *) malloc (5000);
	r_string[31] = (char *) malloc (5000);
	r_string[32] = (char *) malloc (5000);
	r_string[33] = (char *) malloc (5000);
	r_string[34] = (char *) malloc (5000);
	r_string[35] = (char *) malloc (5000);
	r_string[36] = (char *) malloc (5000);
	r_string[37] = (char *) malloc (5000);
	r_string[38] = (char *) malloc (5000);
	r_string[39] = (char *) malloc (5000);
	r_string[40] = (char *) malloc (5000);
	ft_bzero(r_string[0], 1);
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
			if (ft_strlen((const char *)r_string[0]) != 0)
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
	char	**splitted = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	int i = 0;
	while (splitted[i] != NULL)
	{
		printf("[%s]", splitted[i]);
		i++;
	}
	printf("%s", splitted[i]);
	return (0);
}*/
