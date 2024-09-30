/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:53 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:35 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (*needle == '\0')
        return (char *)haystack;

    i = 0;
    while (i < len && haystack[i])
    {
        j = 0;
        while (haystack[i + j] && needle[j] && (i + j) < len && haystack[i + j] == needle[j])
        {
            j++;
        }
        if (needle[j] == '\0')
            return (char *)&haystack[i];
        i++;
    }

    return NULL;
}
