/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:54:32 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:26 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    size_t i;
    char a;

    a = (char)c;
    i = 0;

    while (s[i])
    {
        if (s[i] == a)
        {
            return (char *)&s[i];
        }
        i++;
    }
    if (s[i] == a)
    {
        return (char *)&s[i];
    }
    return NULL;
}
