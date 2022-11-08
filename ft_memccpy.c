/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:45:18 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/08 15:45:20 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(
		void *restrict dest, const void *restrict src, int c, size_t n)
{
	size_t		i;
	char		*string_dest;
	const char	*string_src;
	int			ischarfound;

	string_src = src;
	string_dest = dest;
	ischarfound = 0;
	i = 0;
	while (i < n && !(ischarfound))
	{
		if (string_src[i] == (char)c)
			ischarfound = 1;
		string_dest[i] = string_src[i];
		i++;
	}
	return (dest);
}
