/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:49:12 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:29 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    size_t i;

    char *ptr;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    
    ptr = (char *)malloc(i + 1);
    if (!ptr)
    {
        return NULL;
    }

    ptr[i] = '\0';
    while (i > 0)
    {
        i--;
        ptr[i] = s[i];
    }
    return (ptr);
}