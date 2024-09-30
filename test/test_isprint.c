/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:01:48 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:00 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"

void test_function_name()
{
   printf("《ft_isprint.c》");
   printf("\n");
}

void test_isprint()
{
   // int tests[];
   // int i;
   // int num;
   // tests = {-10, -1, 0, ' ', '@', 'A', 'M', 'Z', '[', '`', 'a', 'm', 'z', '{', '}', 127, 128, 150}
   // i = 0;
   int tests[] = {
    // 全ての数字
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

    // アルファベットの大文字
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z',

    // アルファベットの小文字
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z',

    // 境界値および非アルファベット/非数字の文字
    '-', ' ', '/', ':', '@', '[', '`', '{', '~', '^', '|', '\\', ',', ';', '\b', '\f', '\v',

    // 制御文字
    '\n', '\t', '\r',

    // 負の値
    -128, -127, -1, 

    // NULL文字
    '\0',

    // 拡張ASCIIや境界値
    127, 128, 150, 255, 0xFF01, 0xFF5E, 0xFFE0
   };

   int num;
   int i = 0;
   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_isprint(tests[i]);
      honke = isprint(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(GREEN "OK " RESET);
      }
      else
      {
         printf(RED "FAILED " RESET);
      }
      i++;
   }
   printf("\n");

   i = 0;

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_isprint(tests[i]);
      honke = isprint(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(CYAN "%d" RESET,honke);
      }
      else
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(YEALLOW "%d" RESET,honke);
      }
      i++;
   }
   printf("\n");
   printf("\n");
}

int main() 
{
   test_function_name();
   test_isprint();
   return 0;
}
