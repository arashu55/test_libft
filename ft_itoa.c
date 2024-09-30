/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:34:19 by ashu              #+#    #+#             */
/*   Updated: 2024/09/23 00:47:37 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_countlen(int n)
{
    size_t len;

    len = 0;

    if (n == 0)
        return 1;
    if (n < 0)
        len++;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return len;
}

static char *ft_lengetmem(size_t len)
{
    char *str;
    str = (char *)malloc(sizeof(char) * (len + 1));

    if (!str)
        return NULL;
    return str;
}

static void ft_memsetstr(char *str, int n, size_t len)
{
    str[len] = '\0';
    len--;

    if (n == 0)
        str[0] = '0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n; // 正に変える。
    }
    while (n > 0)
    {
        str[len] = (n % 10) + '0';
        len--;
        n = n / 10;
    }
}

char *ft_itoa(int n)
{
    size_t len;
    char *str;

    len = ft_countlen(n); //桁数を数える
    str = ft_lengetmem(len); //メモリ確保

    if (!str)
        return NULL;

    ft_memsetstr(str, n, len);
    return str;
}
