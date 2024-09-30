/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:51:06 by ashu              #+#    #+#             */
/*   Updated: 2024/09/25 08:30:53 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t i;
    char *str;

    if (!s || !f)
        return (NULL);
    
    str = ft_strdup(s);

    if (!str)
        return (NULL);
    
    i = 0;
    while (str[i])
    {
        str[i] = f(i, str[i]);
        i++;
    }
    return (str);
}
