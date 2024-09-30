/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:22:09 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:51 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_isupper(int c)
{
    if ('A' <= c && c <= 'Z')
    {
        return(1);
    }
    return(0);
}

static int ft_islower(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return(1);
    }
    return(0);
}

int	ft_isalpha(int c)
{
   return (ft_isupper (c)|| ft_islower(c));
}
