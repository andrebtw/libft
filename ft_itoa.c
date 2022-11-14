/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:55 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/12 15:58:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	int_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -1 * n;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_is_zero(void)
{
	char	*r_string;

	r_string = (char *) malloc (sizeof(char) * 2);
	r_string[0] = '0';
	r_string[1] = '\0';
	return (r_string);
}

char	*ft_itoa(int n)
{
	char	*r_string;
	int		nb_len;
	int		is_neg;
	long	n_long;

	n_long = (long)n;
	nb_len = int_size(n_long);
	is_neg = 0;
	if (n == 0)
		return (ft_is_zero());
	r_string = (char *) malloc (nb_len * sizeof(char) + 1);
	if (r_string == NULL)
		return (NULL);
	if ((long)n < 0)
	{
		n_long = -1 * n_long;
		is_neg = 1;
	}
	r_string[nb_len] = '\0';
	nb_len--;
	while (nb_len >= 0)
	{
		r_string[nb_len] = n_long % 10 + '0';
		n_long = n_long / 10;
		nb_len--;
	}
	if (is_neg)
		r_string[0] = '-';
	return (r_string);
}
/*
int	main(void)
{
	char *str = ft_itoa(-4894849489894);
	printf("%s", str);
	return (0);
}
*/