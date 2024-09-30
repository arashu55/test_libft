/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:51:43 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:28 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;

    while (dst[i] && i < dstsize)
    {
        i++;
        j++;
    }

    if (dstsize != 0 && dstsize < j)
    {
        while (src[i - j] && (i < dstsize - 1))
        {
            dst[i] = src[i - j];
            i++;
        }
        dst[i] = '\0';

        while (src[i - j])
        {
            i++;
        }
        return i;
    }

    i = 0;

    while (src[i])
    {
        i++;
    }
    return dstsize + i; 
}