/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:37:37 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/02 15:37:37 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *restrict dest, const char *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int	main(void)
{
	char src[20] = "Hello World";
	char dest[20];
	ft_strncpy(dest, src, 12);
	printf("%s\n", dest);
	return (0);
}