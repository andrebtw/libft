/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:23:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/11/07 21:27:59 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	size_count(char *dst, const char *src, size_t size)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (dst[i] != '\0')
        i++;
    while (src[j] != '\0')
        j++;
    if (i + j > (int)size)
    {
        if (i > j)
            return (j + size);
        return (i + size);
    }
    return (i + j);
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