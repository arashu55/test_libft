/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:25:13 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:30 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    
    i = 0;
    
    if (dstsize != 0)
    {
        while (i < dstsize - 1 && src[i] != '\0')
        {
            dst[i] = src [i];
            i++;
        }
        dst[i] = '\0';
    }
   
    // i = 0;  これいらないらしいけど確かにそうだわ！！
    while (src[i] != '\0')
    {
        i++;
    }
    return i;
}