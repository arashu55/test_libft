/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:26:54 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:55 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_atoi(const char *str)
{

    int sign;
    long long result;

    while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' || *str == '\f' || *str == '\v')
    {
        str++;
    }
 
    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            sign = -1;
        }
        str++;
        
    }

    result = 0;
    while (ft_isdigit(*str))
    {
        result = result * 10 + (*str - '0');
        if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && (*str - '0') > 7))
        {
            if (sign == 1)
            {
                printf("Overflow detected\n");
                return((int)LONG_MAX);
            }
            else if(sign == -1)
            {
                return((int)LONG_MIN);
            }
        }
        printf("Result updated: result = %lld, str = %s\n", result, str);
        str++;
    }

    return((int)result * sign);
}
