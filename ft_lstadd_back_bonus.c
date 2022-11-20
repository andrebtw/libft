/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:08:32 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/20 11:08:32 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->next = NULL;
			return ;
		}
		tmp->next = tmp;
	}
	new->next = *lst;
	*lst = new;
}