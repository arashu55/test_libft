/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:38:41 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:13 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char * a;
    const char * b;
    size_t i;

    a = (char *)dest;
    b = (const char *)src;
    i = 0;

    while (i < n)
    {
        a[i] = b[i];
        i++;
    }

    return dest;
}