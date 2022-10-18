/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:08:34 by andre             #+#    #+#             */
/*   Updated: 2022/10/08 19:57:56 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char character)
{
	if (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	neg_mult;
	int	i;

	i = 0;
	number = 0;
	neg_mult = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		neg_mult = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	if (number == 0)
		return (0);
	return (number * neg_mult);
}
