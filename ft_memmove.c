/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:15:26 by anrodri2          #+#    #+#             */
/*   Updated: 2022/10/31 12:15:26 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	i;
	char	*string_dest;
	const char	*string_src;

	string_src = src;
	string_dest = dest;
	i = 0;
	while (i < n)
	{
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*string_dest;
	char	*string_src;

	ft_memcpy(string_src, src, n);
	string_dest = dest;
	i = 0;
	while (i < n)
	{
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}