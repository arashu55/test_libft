/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:33:26 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:34 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;

    while(i < n && s1[i] != '0' && s2[i] != '\0')
    {
        if (s1[i] - s2[i] < 0)
        {
            return((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        else if (s1[i] - s2[i] > 0)
        {
            return((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        i++;
    }
    return(0);
}