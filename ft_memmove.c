/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:45:34 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/08 15:45:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t		i;
	char		*string_dest;
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
	char		*string_dest;
	const char	*string_src;
	int			i;

	i = (int)n - 1;
	string_dest = dest;
	string_src = src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (i >= 0)
	{
		string_dest[i] = string_src[i];
		i--;
	}
	return (dest);
}
