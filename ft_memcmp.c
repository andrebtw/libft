/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:48:36 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/07 22:02:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned long		*string1;
	const unsigned long		*string2;

	string1 = s1;
	string2 = s2;
	i = 0;
	
	if (n == 0)
		return (0);
	while ((string1[i] && string1[i] == string2[i]) && i <= n)
		i++;
	return (string1[i] - string2[i]);
}
