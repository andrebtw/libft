/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:08:01 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/03 12:08:01 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0' && n < 0)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + (i - j));
		i++;
		n--;
	}
	return (NULL);
}
#include <stdio.h>
int	main(void)
{
	char haystack[50] = "Hello World";
	char needle[50] = "a";
	char *test = strnstr(haystack, needle);
	printf("%s\n", test);
	return (0);
}