/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:55:20 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/23 15:05:34 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_lst;

	while (lst != NULL)
	{
		r_lst = malloc (sizeof(t_list));
		if (!r_lst)
		{
			ft_lstdelone(r_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&r_lst, r_lst->cont);
	}
	return (r_lst);
}
