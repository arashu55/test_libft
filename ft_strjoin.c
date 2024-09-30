/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:06:51 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 13:57:12 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    size_t len;
    char *ptr;

    if (!s1 || !s2)
    {
        return (NULL);
    }

    len = ft_strlen(s1) + ft_strlen(s2);

    ptr = (char *)malloc(len + 1);
    if (!ptr)
    {
        return (NULL);
    }

    i = 0;
    while (s1[i] != '\0')
    {
        ptr[i] = s1[i];
        i++;
    }

    j = 0;
    while (s2[i] != '\0')
    {
        ptr[i] = s2[j];
        i++;
        j++;
    }

    ptr[len] = '\0';
    
    return(ptr);
}
