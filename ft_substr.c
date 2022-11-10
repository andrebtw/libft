/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:19 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/10 17:03:06 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_strlen_int(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			len_count;
	char			*r_string;

	i = start;
	len_count = 0;
	if (ft_strlen_int(s) <= (int)start)
	{
		r_string = (char *) malloc (sizeof(char));
		r_string[0] = '\0';
		return (r_string);
	}
	r_string = (char *) malloc (len * sizeof(char) + 1);
	if (r_string == NULL)
		return (NULL);
	while (s[i] != '\0' && len_count < len)
	{
		r_string[len_count] = s[i];
		len_count++;
		i++;
	}
	if (r_string[len_count] != '\0')
		r_string[len_count] = '\0';
	return (r_string);
}
