/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:36:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/21 16:06:39 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp2 != NULL)
	{
		del(tmp);
		free(tmp);
		tmp2->next = tmp2;
		tmp->next = tmp2;
	}
}