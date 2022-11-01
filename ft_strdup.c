/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:22:31 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/01 15:22:31 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*return_string;
	unsigned int	i;
	unsigned int	string_size;

	string_size = 0;
	while (s[string_size] != '\0')
		string_size++;
	return_string = (char *) malloc(string_size * sizeof(char));
	if (return_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		return_string[i] = s[i];
		i++;
	}
	return_string[i] = '\0';
	return (return_string);
}