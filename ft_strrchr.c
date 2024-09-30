/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:04:26 by ashu              #+#    #+#             */
/*   Updated: 2024/09/17 14:40:50 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    int b;
    char a;

    a = (char)c;
    i = 0;
    b = -1;

    while (s[i])
    {
        if (s[i] == a)
        {
            b = i;
        }
        i++;
    }

    if (s[i] == a)
    {
        b = i;
    }

    if (b == -1)
    {
        return NULL;
    }
    return (char *)&s[b];
}
