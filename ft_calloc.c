/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:25:28 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:20 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t i;
    char *s;

    s = (char *)malloc(nmemb * size);
    
    if (s == NULL)
    {
        return NULL;
    }

    i = 0;
    while (i < nmemb * size)
    {
        s[i] = 0;
        i++;
    }
    return (void *)s;
}