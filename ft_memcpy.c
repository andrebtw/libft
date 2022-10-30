/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:52:50 by andre             #+#    #+#             */
/*   Updated: 2022/10/23 21:49:15 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	i;
	char	*string_dest;
	char	*string_src;

	string_src = (char *)src;
	i = 0;
	while (i < n)
	{
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char dest[20] = "hello";
	char src[20] = "world";
	ft_memcpy(dest, src, 4);
	printf("%s", dest);
	return (0);
}
