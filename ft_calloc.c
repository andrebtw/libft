/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:44:57 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/14 13:16:21 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*array;
	size_t			i;
	size_t			k;

	k = 0;
	if (SIZE_MAX / size <= count)
		return (NULL);
	array = (unsigned char *) malloc ((count * size));
	if (array == NULL)
		return (NULL);
	i = count * size;
	while (k < i)
	{
		array[k] = '\0';
		k++;
	}
	return ((void *)array);
}
