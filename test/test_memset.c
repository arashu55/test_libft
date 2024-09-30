/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:17:49 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:01:59 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"

void test_function_name()
{
   printf("《ft_memset.c》");
   printf("\n");
}

void test_memset()
{
   // int tests[];
   // int i;
   // int num;
   // tests = {-10, -1, 0, ' ', '@', 'A', 'M', 'Z', '[', '`', 'a', 'm', 'z', '{', '}', 127, 128, 150}
   // i = 0;
   const char *moji[] = {
    "This is a test string.",
    "Another test string."
    };

   int num;
   int i = 0;
 

   struct{
    char *mem;
    int c;
    size_t len;
   } tests[] = {
    {(char *)moji[0], 'A', 5},
    {(char *)moji[1], 'b', 4},
   };

   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {
      void *ft;
      void *honke;  
      ft = ft_memset(tests[i].mem, tests[i].c, tests[i].len);
      honke = memset(tests[i].mem, tests[i].c, tests[i].len);

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
      void *ft;
      void *honke;  
      ft = ft_memset(tests[i].mem, tests[i].c, tests[i].len);
      honke = memset(tests[i].mem, tests[i].c, tests[i].len);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%p" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(CYAN "%p" RESET,honke);
      }
      else
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%p" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(YEALLOW "%p" RESET,honke);
      }
      i++;
   }
   printf("\n");
   printf("\n");
}

int main() 
{
   test_function_name();
   test_memset();
   return 0;
}