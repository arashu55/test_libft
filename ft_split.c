/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:59:20 by ashu              #+#    #+#             */
/*   Updated: 2024/09/19 19:30:34 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_countlen(const char *s, char c, size_t *length)
{
    size_t word_count;
    size_t i;
    size_t word_len;

    word_count = 0;
    i = 0;

    while (s[i])
    {
        if (s[i] == c)
        {
            i++;
        }
        else
        {
            word_len = 0;
            while (s[i] && s[i] != c)
            {
                word_len++;
                i++;
            }

            length[word_count] = word_len;
            word_count++;
        }
    }
    return word_count;
}

static char *ft_wordmemcpy(const char *s, size_t start,size_t len)
{
    char *word;

    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;

    size_t i;

    i = 0;
    while (i < len)
    {
        word[i] = s[start + i];
        i++;
    }
    word[len] = '\0';

    return word;
}

static char **ft_wordcountmem(int word_count)
{
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return NULL;
    return result;
}

static void ft_memfree(char **result, size_t count)
{
    while (count > 0)
    {
        free(result[count -1]);
        count--;
    }
    free(result);
}


char **ft_split(const char *s, char c)
{
    size_t word_count;
    char **result;
    size_t i;
    size_t start;

    if (!s)
        return NULL;

    size_t *length = (size_t *)malloc(sizeof(size_t) * (ft_strlen(s) + 1));
    if (!length)
        return NULL;

    word_count = ft_countlen(s, c, length);
    
    result = ft_wordcountmem(word_count);

    if (!result)
    {
        free(length);
        return NULL;
    }

    i = 0;
    start = 0;
    while (i < word_count)
    {
        result[i] = ft_wordmemcpy(s, start, length[i]);

        if (! result[i])
        {
            ft_memfree(result, i);
            free(length);
            return NULL;
        }

        start += length[i];
        i++;
    }

    result[word_count] = NULL;
    free(length);
    return result;
}
