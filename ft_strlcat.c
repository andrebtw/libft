/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:35:35 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/02 16:35:35 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	src_size;
	unsigned int	dest_size;

	src_size = 0;
	dest_size = 0;
	while (dst[dest_size] != '\0')
		dest_size++;
	while (src[src_size] != '\0' && size > 0)
	{
		dst[dest_size] = src[src_size];
		dest_size++;
		src_size++;
		size--;
	}
	dst[dest_size] = '\0';
	return (dest_size);
}

#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char src[20] = " World";
	char dest[20] = "Hello";
	size_t num = strlcat(dest, src, 20);
	printf("Dest : %s\n", dest);
	printf("size_t returning : %d", num);
	return (0);
}