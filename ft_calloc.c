/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/09 09:55:14 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*array;
	unsigned long long	i;

	array = (unsigned char *) malloc (count * size);
	if (count == 0 || size == 0)
		return (NULL);
	if (array == NULL)
		return (NULL);
	i = count * size;
	while (i > 0)
	{
		array[i] = '\0';
		i--;
	}
	array[0] = '\0';
	return ((void *)array);
}
