/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 06:26:11 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 13:57:35 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *ptr;

    if (!s)
    {
        return (NULL);
    }

    ptr = (char *)malloc(len + 1);

    i = 0;
    while (i < len)
    {
        ptr[i] = s[i + start];
        i++;
    }
    ptr[i] = '\0';
    return(ptr);
}