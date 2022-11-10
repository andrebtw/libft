/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/10 16:33:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*array;
	size_t			i;

	array = (unsigned char *) malloc ((count * size) + size);
	if (array == NULL)
		return (NULL);
	i = count * size;
	if (count * size > SIZE_MAX)
		return (NULL);
	while (i > 0)
	{
		array[i] = '\0';
		i--;
	}
	array[0] = '\0';
	return ((void *)array);
}
