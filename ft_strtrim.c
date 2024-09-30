/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 07:52:22 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 13:57:20 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t s;
    size_t e;
    char *ptr;

    if (!s1 || !set)
    {
        return (NULL);
    }

    s = 0;
    while (s1[s] && ft_strchr(set, s1[s]))
    {
        s++;
    }

    e = ft_strlen(s1);
    while (e > s && ft_strchr(set, s1[e - 1]))
    {
        e--;
    }

    ptr = (char *)malloc((e - s + 1));

    if (!ptr)
    {
        return (NULL);
    }

    ft_strlcpy(ptr, &s1[s], e - s + 1);

    return (ptr);
}
