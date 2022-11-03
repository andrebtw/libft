/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:45:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/03 11:45:44 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + (i - j));
		i++;
	}
	return (NULL);
}
#include <stdio.h>
int	main(void)
{
	char haystack[50] = "Hello World";
	char needle[50] = "a";
	char *test = strstr(haystack, needle);
	printf("%s\n", test);
	return (0);
}