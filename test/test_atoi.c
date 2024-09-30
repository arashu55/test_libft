/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:02:56 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:06 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"

void test_function_name()
{
   printf("《ft_atoi.c》");
   printf("\n");
}

void test_atoi()
{
   const char *tests[] = {
    "0",                        // 0
    "123",                      // 正の整数
    "-123",                     // 負の整数
    "+123",                     // 正の符号付き整数
    "   42",                    // 先頭に空白があるケース
    "   -42",                   // 先頭に空白があり、負の整数
    "2147483647",               // INT_MAX (32-bit)
    "-2147483648",              // INT_MIN (32-bit)
    "4294967295",               // unsigned int 最大値
    "0000123",                  // 先頭に0がある数字
    "   +00123",                // 先頭に空白と0がある正の数字
    "-00123",                   // 先頭に0がある負の数字
    "123abc",                   // 数字の後に無効な文字
    "-123abc",                  // 負の数字の後に無効な文字
    "abc123",                   // 先頭が無効な文字列
    "",                         // 空文字列
    " ",                        // スペースのみの文字列
    "   ",                      // 複数の空白
    "\t\n\r\v\f42",             // 制御文字と空白が先頭にあるケース
    "\n123",                    // 改行が先頭にある数字
    "2147483648",               // INT_MAX+1 (オーバーフロー)
    "-2147483649",              // INT_MIN-1 (アンダーフロー)
    "+-123",                    // 無効な符号の組み合わせ
    "--123",                    // 無効な符号
    "++123",                    // 無効な符号
    "  -+123",                  // 符号の混在と空白
    "   000000000000000000000000000042", // 無意味な0の連続

    // より特殊なケース
    "\xff",                     // 無効なASCIIコード
    "\x80\x81\x82\x83\x84",     // 拡張ASCII
    "こんにちは",               // 非ASCII文字（日本語）
    "👍123",                    // 絵文字が先頭にある場合
    NULL,                       // NULLポインタ

    // メモリ外アクセスを誘発するケース（通常はエラーハンドリングが必要）
    // (const char *)0xFFFFFFFF, // メモリ外のアドレス
    // (const char *)0x00000000, // 明示的にNULLポインタ
    };


   int num;
   int i = 0;
   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {    
      if (tests[i] == NULL) {
          printf("【test%d】", i);
          printf(RED "SKIPPED " RESET);
          i++;
          continue;
      }
      int ft;
      int honke;  
      ft = ft_atoi(tests[i]);
      honke = atoi(tests[i]);

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
      ft = ft_atoi(tests[i]);
      honke = atoi(tests[i]);

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
   test_atoi();
   return 0;
}
