/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:47:02 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:14 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char * a;
    const unsigned char * b;
    unsigned char c[n];
    size_t i;

    a = (unsigned char *)dest;
    b = (const unsigned char *)src;
    i = 0;

    while (i < n)
    {
        c[i] = b[i];
        i++;
    }
    
    i = 0;
    while (i < n)
    {
        a[i] = c[i];
        i++;
    }

    return dest;
}

// スタックオーバーフロー対策のため、バファをヒープ領域にする必要あり。