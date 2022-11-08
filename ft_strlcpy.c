/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:23:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/08 15:05:33 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	size_count(char *dst, const char *src, size_t size)
{
    int    dst_size;
    int    src_size;

    dst_size = 0;
    src_size = 0;
    while (dst[dst_size] != '\0')
        dst_size++;
    while (src[src_size] != '\0')
        src_size++;
    if (size == 0)
        return (src_size);
    if (dst_size > (int)size)
        return ((int)size + src_size);
    else
        return (dst_size + src_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    unsigned int	src_size;
    unsigned int	dest_size;
    size_t			return_size;

    return_size = size_count(dst, src, size);
    src_size = 0;
    dest_size = 0;
    while (dst[dest_size] != '\0')
    {
        dest_size++;
        size--;
    }
    while (src[src_size] != '\0' && (int)size - 1 > 0)
    {
        dst[dest_size] = src[src_size];
        dest_size++;
        src_size++;
        size--;
    }
    dst[dest_size] = '\0';
    return (return_size);
}