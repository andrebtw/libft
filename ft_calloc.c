/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/08 15:45:00 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = malloc (count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, count);
	return (array);
}
