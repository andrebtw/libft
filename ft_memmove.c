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
	char	char_src;
	const char	*string_src;

	string_dest = dest;
	string_src = src;
	i = 0;
	while (i < n)
	{
		char_src = string_src[i];
		string_dest[i] = char_src;
		i++;
	}
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char str[100] = "Learningisfun";
	char *dest;

	ft_memmove(str + 8, str, 10);
	printf("%s", str);
	return (0);
}