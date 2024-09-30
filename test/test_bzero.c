/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:47:19 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:03:54 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"

int flag = 1;

void test_function_name()
{
   printf("《ft_bzero.c》");
   printf("\n");
}

void print_memory(const void *mem, size_t len)
{
    size_t i;
    const unsigned char *bytes;
    
    i = 0;
    bytes = (const unsigned char *)mem;

    while (i < len)
    {
        if (flag == 1)
        {
            printf(CYAN "%02X " RESET, bytes[i]);
        } 
        else
        {
            printf(YEALLOW "%02X " RESET, bytes[i]);
        }
        i++;
    }
    printf("\n");
}

void test_bzero()
{
   // int tests[];
   // int i;
   // int num;
   // tests = {-10, -1, 0, ' ', '@', 'A', 'M', 'Z', '[', '`', 'a', 'm', 'z', '{', '}', 127, 128, 150}
   // i = 0;
    // 文字列リテラルではなく、動的にメモリを確保
    char *moji[] = {
        strdup("This is a test string."), // strdupで文字列をコピーして動的にメモリ確保
        strdup("Another test string.")
    };

    char *baka[] = {
        strdup("This is a test string."),
        strdup("Another test string.")
    };

    struct{
    void *b;
    size_t len;
   } tests[] = {
    {moji[0], 5},
    {moji[1], 4},
   };

   struct{
    void *d;
    size_t lan;
   } test2[] = {
    {baka[0], 5},
    {baka[1], 4},
   };


   int num;
   int flag2;

   flag2 = 1;
   int i = 0;
   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {
        printf("【test%d】", i);

        // メモリの比較
        if (memcmp(tests[i].b, test2[i].d, tests[i].len + 5) == 0)
        {
            printf(GREEN "OK\n" RESET);
        }
        else
        {
            printf(RED "FAILED\n" RESET);
            flag2 = 0;
        }

        printf("\n");
        // オリジナル
        printf("Before bzero (libft): ");
        print_memory(tests[i].b, tests[i].len + 5);  // 元のメモリ内容を表示（長さ調整）

        // 自作
        ft_bzero(tests[i].b, tests[i].len);

        // 結果を表示
        printf("After bzero (libft): ");
        print_memory(tests[i].b, tests[i].len + 5);

        if (flag2 == 0)
        {
            flag = 0;
        }

        // 本家bzeroを適用
        printf("Before bzero (linux): ");
        print_memory(test2[i].d, test2[i].lan + 5);

        bzero(test2[i].d, test2[i].lan);

        // 結果を表示
        printf("After bzero (linux): ");
        print_memory(test2[i].d, test2[i].lan + 5);

        printf("\n");
        
        flag = 1;
        flag2 = 1;
        i++;
    }
    // 確保したメモリの解放
    for (i = 0; i < num; i++)
    {
        free(moji[i]);
        free(baka[i]);
    }

//       char * ft;
//       char * honke;  
//       ft_bzero(tests[i].b, tests[i].len);
//       ft = moji[i];
//       bzero(test2[i].d, test2[i].lan);
//       honke = baka[i];

//       printf("【test%d】", i);
//       if (ft == honke)
//       {
//          printf(GREEN "OK " RESET);
//       }
//       else
//       {
//          printf(RED "FAILED " RESET);
//       }
//       i++;
//    }
//    printf("\n");

//    i = 0;

//    while (i != num)
//    {
//       char * ft;
//       char * honke;  
//       ft_bzero(tests[i].b, tests[i].len);
//       ft = moji[i];
//       bzero(test2[i].d, test2[i].lan);
//       honke = baka[i];

//       printf("【test%d】", i);
//       if (ft == honke)
//       {
//          printf(SHADOW "libft is " RESET);
//          printf(CYAN "%s" RESET,ft);
//          printf(SHADOW "linux is " RESET);
//          printf(CYAN "%s" RESET,honke);
//       }
//       else
//       {
//          printf(SHADOW "libft is " RESET);
//          printf(CYAN "%s" RESET,ft);
//          printf(SHADOW "linux is " RESET);
//          printf(YEALLOW "%s" RESET,honke);
//       }
//       i++;
//    }
//    printf("\n");
//    printf("\n");
}

int main() 
{
   test_function_name();
   test_bzero();
   return 0;
}
