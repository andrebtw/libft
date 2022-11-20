/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:41:42 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/19 23:41:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H_BONUS_
# define __LIBFT_H_BONUS_

#include <string.h>

// ---BONUS--- //
typedef struct s_list
{
    void *content;
    struct s_list *next;
}   t_list;

t_list	*ft_lstnew(void *content);

#endif